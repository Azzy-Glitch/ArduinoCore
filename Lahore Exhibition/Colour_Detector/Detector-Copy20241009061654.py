import cv2
import numpy as np

# Function to get contours and detect shapes
def get_contours(mask, color_name, color, output_img):
    contours, _ = cv2.findContours(mask, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
    for cnt in contours:
        area = cv2.contourArea(cnt)
        if area > 1000:  # Skip small contours to reduce noise
            peri = cv2.arcLength(cnt, True)
            approx = cv2.approxPolyDP(cnt, 0.02 * peri, True)
            x, y, w, h = cv2.boundingRect(approx)
            
            if len(approx) == 3:
                shape = "Triangle"
            elif len(approx) == 4:
                aspect_ratio = w / float(h)
                shape = "Square" if 0.95 <= aspect_ratio <= 1.05 else "Rectangle"
            else:
                shape = None  # We'll handle circles separately
            
            if shape:
                cv2.putText(output_img, f"{shape} - {color_name}", (x, y - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.5, color, 2)
                cv2.drawContours(output_img, [approx], 0, color, 2)

# Function to detect circles
def detect_circles(mask, output_img, color_name, color):
    circles = cv2.HoughCircles(mask, cv2.HOUGH_GRADIENT, dp=1.2, minDist=30, param1=50, param2=30, minRadius=10, maxRadius=100)
    if circles is not None:
        circles = np.round(circles[0, :]).astype("int")
        for (x, y, r) in circles:
            cv2.circle(output_img, (x, y), r, color, 2)
            cv2.putText(output_img, f"Circle - {color_name}", (x - r, y - r - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.5, color, 2)

# Initialize the webcam
cap = cv2.VideoCapture(0)

# Main loop
while True:
    ret, img = cap.read()
    if not ret:
        break
    
    img = cv2.resize(img, (640, 480))
    hsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)

    # Define refined color ranges
    color_ranges = {
        'red1': ([0, 120, 70], [10, 255, 255], (0, 0, 255)),
        'red2': ([170, 120, 70], [180, 255, 255], (0, 0, 255)),
        'green': ([36, 100, 100], [86, 255, 255], (0, 255, 0)),
        'blue': ([100, 150, 0], [130, 255, 255], (255, 0, 0))
    }

    # Process each color
    for color_name, (lower, upper, bgr_color) in color_ranges.items():
        lower_np = np.array(lower)
        upper_np = np.array(upper)
        mask = cv2.inRange(hsv, lower_np, upper_np)
        
        # Apply erosion and dilation to clean up the mask
        mask = cv2.erode(mask, None, iterations=2)
        mask = cv2.dilate(mask, None, iterations=2)
        
        # Detect and draw contours
        get_contours(mask, color_name, bgr_color, img)
        
        # Convert mask to grayscale for circle detection
        gray_mask = cv2.cvtColor(cv2.bitwise_and(img, img, mask=mask), cv2.COLOR_BGR2GRAY)
        detect_circles(gray_mask, img, color_name, bgr_color)

    # Display the result
    cv2.imshow("Color and Shape Detection", img)

    if cv2.waitKey(1) == ord('q'):
        break

# Release resources
cap.release()
cv2.destroyAllWindows()
