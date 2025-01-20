import win32com.client
import speech_recognition as sr
import time
import requests
import openai
from tkinter import *
from tkinter import ttk
import threading
import pygame

AI_NAME = "Jarvis"

QANDA = {
    "Introduce your college?" : "Our college is dedicated to providing a nurturing environment for learning and growth. We strive to foster academic excellence, personal development, and a vibrant community.",
    "What are the facilities provided by your college" : "Our college offers a range of facilities including classrooms equipped with modern technology, a well-stocked library, laboratory facilities for various disciplines, sports facilities, a cafeteria, administrative offices, and dormitory accommodations.",
    "What is the purpose of each floor in your college" : "Ground Floor: Houses administrative offices, the cafeteria, and main entrance.First Floor: Classrooms and academic departments.Second Floor: Additional classrooms, laboratories, and academic resources.",
    "Can you provide information about the cafeteria services available" : "Our cafeteria provides a variety of delicious and nutritious meals for students and staff, ensuring everyone has access to quality dining options.",
    "Provide me some details about the car parking" : "We have designated parking areas available for students, staff, and visitors. Our smart parking system efficiently manages parking spaces to ensure convenience and ease of access.Park like the future!** College unveils an automatic vertical parking system on the left side. ",
    "I want to give suggestions on how you can improve your college" : "We welcome any suggestions or feedback on how we can enhance our college environment and services to better meet the needs of our students and community.",
    "I have a complaint" : "If you have any complaints, please bring them to our attention, and we will address them promptly to ensure your concerns are resolved satisfactorily.",
    "Where is the parking area" : "Park like the future!** College unveils an automatic vertical parking system on the left side.",
    "Introduce me your smart parking system" : "We have designated parking areas available for students, staff, and visitors. Our smart parking system efficiently manages parking spaces to ensure convenience and ease of access.Park like the future!** College unveils an automatic vertical parking system on the left side.",
    "Where is the staffroom" : "The staffroom is situated on the first floor of the college building.Conveniently located near the Principal's office for easy access.Directly opposite the Principal's office .",
    "Where is the principal office" : "Conveniently positioned on the ground floor, the Principal's office is just steps away from the main entrance, ensuring easy access for all. ",
    "Where are the gents or ladies washroom" : "Washrooms are conveniently located on each floor of the college building, with separate facilities for gentlemen and ladies.",
    "Where is the admin office" : "The administrative office is located on the first floor. Once you head up the stairs, turn right and you'll find it near the cafeteria.",
    "Where are the classrooms" : "Spread across the first and second floors, our college classrooms offer conducive environments for learning. First-year students benefit from dedicated spaces on the first floor, while sophomore classes are conveniently located on the second floor.Go! and explore our vibrant learning spaces today!",
    "Can i meet a person to get help" : "If you require assistance, please feel free to approach any staff member, or visit the administrative office for guidance and support.",
    "Would you Identify disasters happened or alerts!" : "Our college has measures in place to identify and respond to disasters or emergencies effectively, ensuring the safety and well-being of everyone on campus.",
    "I would like to explore first floor" : "You are welcome to explore the first floor of the college building at your leisure.",
    "I would like to explore second floor" : "You are welcome to explore the first floor of the college building at your leisure.",
    "What can you do" : "I'm your personal college companion! Whether you need help finding resources, managing your schedule, or just need some academic advice, I'm here to support you.",
    "Help me choose a major" : "We provide guidance and resources to help students choose a major that aligns with their interests, skills, and career goals.",
    "What are the prerequisites for Calculus" : "Prerequisites for courses vary depending on the program of study. Please consult the academic department or advisor for specific information.",
    "What are the tuition fees for the college" : "The tuition fees for the college are outlined in our official fee schedule, which is available upon request or on our website.",
    "What are the application deadlines for the college" : "For information regarding application deadlines, please contact the admissions office for assistance.",
    "How can I apply for financial aid" : "Information on applying for financial aid, including scholarships, grants, and loans, can be obtained from the financial aid office.",
    "What are the contact details for the college admission office" : "You can find contact details for the admissions office on our website or by inquiring at the administrative office.",
    "What are the college's academic resources?" : "Our college offers a wide range of academic resources, including a library stocked with books, journals, online databases, and other learning materials to support students' academic endeavors.",
    "What are the college's extracurricular activities?" : "We offer a variety of extracurricular activities, including sports teams, clubs, cultural organizations, and community service opportunities, to enrich the student experience and promote holistic development.",
    "What are the college's dormitories like?" : "Our dormitory facilities provide comfortable accommodations for students, offering a supportive living environment conducive to academic success and personal growth.",
    "What are the college's academic programs?" : "Our college offers diverse academic programs spanning various disciplines, providing students with opportunities for intellectual exploration and professional development.",
    "What are the college's academic departments?" : "We have several academic departments, each dedicated to a specific field of study, staffed by experienced faculty members committed to delivering high-quality education and research opportunities.",
    "What are the college's academic requirements?" : "Admission to our college typically requires meeting specific academic requirements, which may include standardized test scores, high school transcripts, and other criteria depending on the program of interest"
}

pygame.init()

width, height = pygame.display.Info().current_w, pygame.display.Info().current_w

OPTIONS = list(QANDA.keys())
ANSWERS = list(QANDA.values())

WEATHER_API_KEY = "48e895ba1790f7cf1708f66ec4135d85"
OPENAI_API_KEY = "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"

speaker = win32com.client.Dispatch("SAPI.SpVoice")
query = " "

def GUI():
    global text_widget

    window = Tk()
    window.geometry(f"{width}x{height - 50}")
    window.update()

    #Top label AI NAme
    label = Label(window, text="Jarvis AI", bg='black', fg='lime', font=("Consolas", 24))
    label.pack(fill=BOTH)

    #Frame for adding text widget and a scrollbar
    text_frame = Frame(window)

    text_frame.grid_rowconfigure(0, weight=1)
    text_frame.grid_columnconfigure(0, weight=1)

    text_widget = Text(text_frame, font=("Consolas", 16), fg="white", state=DISABLED, bg="#282529")
    text_widget.grid(row=0, column=0, sticky=NSEW)

    scrollbar = ttk.Scrollbar(text_frame, orient="vertical", command=text_widget.yview)
    scrollbar.grid(row=0, column=1, sticky="ns")
    text_widget.config(yscrollcommand=scrollbar.set)

    # quit_button = Button(window, text="X",font=("Consolas", 13), bg="gray", fg="red", width=3, height=1, command=quit)
    # quit_button.place(x=width - 90, y=3)

    text_frame.pack(expand=True, fill=BOTH)

    window.mainloop()

threading.Thread(target=GUI).start()

def gpt(prompt):
    prompt_ai = prompt.replace(AI_NAME.lower(), "")
    openai.api_key = OPENAI_API_KEY
    response = openai.ChatCompletion.create(
        model= "gpt-3.5-turbo",
        messages=[{"role" : "user", "content" : f"{prompt_ai}(please try that your response should not exceed more than 3 lines)"}]
    )

    return response.choices[0].message.content.strip()


def weatherForecast():
    api_key = WEATHER_API_KEY
    city = "Islamabad"

    url = f"http://api.openweathermap.org/data/2.5/weather?q={city}&appid={api_key}"
    response = requests.get(url)

    if response.status_code == 200:
        weather_data = response.json()

        temperatureKelvin = weather_data['main']['temp']
        description = weather_data['weather'][0]['description']
        temperature = round(temperatureKelvin - 273, 2)

        return f"The current temperature in {city} is {temperature} degree celsius and the weather is {description}."

def printOptionsAvailable():
    option_menu = ""
    for index,option in enumerate(OPTIONS):
        if index == 0:
            print("-" * 65)
            option_menu += "-" * 65

        print(f"* {option}")
        option_menu += f"\n* {option}\n"

        if index == len(OPTIONS) - 1:
            print("-" * 65)
            option_menu += "-" * 65
    return option_menu

def getTime(time_or_date):
    if time_or_date == "time":
        return time.strftime("%I:%M:%S %p")
    if time_or_date == "date":
        return time.strftime("%a, %drd of %b %Y")

def getHour():
    hour = int(time.strftime("%H"))
    if hour >= 0 and hour <= 11:
        return "Good Morning"
    elif hour >= 12 and hour <= 16:
        return "Good Afternoon"
    else:
        return "Good Evening"
    
greet = getHour()


def say(text):
    speaker.Speak(text)

def takeCommand():
    global query
    while query != "":
        print("Listening...")
        r = sr.Recognizer()
        with sr.Microphone() as source:
            r.pause_threshold = 1
            r.energy_threshold = 600
            audio = r.listen(source)
            try:
                print("Recognizing...")
                query = r.recognize_google(audio, language="en-in")
                if query == "":
                    continue
                print("User said:", query)
                return query
            except Exception:
                continue
                # return "Some error occured. Sorry from jarvis"

if __name__ == "__main__":

    run = True

    #mainloop
    while True:
        
        #take user input
        query = takeCommand()
        if AI_NAME.lower() in query.lower():
            text_widget.config(state=NORMAL)
            text_widget.insert(END, f"\n\nYou: {query.capitalize()}")
            text_widget.yview(END)
            query = query.lower()

        if any(word in query for word in [f"hello {AI_NAME.lower()}", f"hi {AI_NAME.lower()}", f"hey {AI_NAME.lower()}", f"hay {AI_NAME.lower()}"]):
            #AI introduction
            text_widget.insert(END,f"\n\n{AI_NAME}: {greet}, I am {AI_NAME}, Welcome to our college. How can I help you?")
            text_widget.yview(END)
            say(f"{greet}, I am {AI_NAME}, Welcome to our college. How can I help you?")
            printOptionsAvailable()
            run = True
            continue

        if run and (AI_NAME.lower() in query):
            #AI intro
            if all(word in query for word in ["who","are", "you"]) or all(word in query for word in ["your", "name"]):
                text_widget.insert(END,f"\n\n{AI_NAME}: I am an A.I assistant, named {AI_NAME}, who is here to help you!")
                text_widget.yview(END)
                say(f"I am an A.I assistant, named {AI_NAME}, who is here to help you!")
                continue

            #weather
            if any(word in query for word in ["weather", "forecast", "weather forecast"]):
                weather = weatherForecast()
                text_widget.insert(END,f"\n\n{AI_NAME}: {weather}")
                text_widget.yview(END)
                say(weather)
                continue

            #time
            if "time" in query:
                get_time = getTime('time')
                text_widget.insert(END,f"\n\n{AI_NAME}: Its {get_time}")
                text_widget.yview(END)
                say(f"Its {get_time}")
                continue

            #date
            if any(word in query for word in ["day today", "date"]):
                get_date = getTime('date')
                text_widget.insert(END,f"\n\n{AI_NAME}: Its {get_date}")
                text_widget.yview(END)
                say(f"Its {get_date}")
                continue

            #Menu
            if "menu" in query:
                text_widget.insert(END,f"\n\n{AI_NAME}: Here is the menu!\n{printOptionsAvailable()}")
                text_widget.yview(END)
                say("Here is the menu!")
                printOptionsAvailable()
                continue
            
            #Options
            if query.startswith(OPTIONS[0].lower()) or (("introduce" in query or "introduction" in query) and "college" in query):
                text_widget.insert(END,f"\n\n{AI_NAME}: {ANSWERS[0]}")
                text_widget.yview(END)
                say(ANSWERS[0])
            elif query.startswith(OPTIONS[1].lower()) or ("facilities" in query and "college" in query) or ("facilities" in query):
                text_widget.insert(END,f"\n\n{AI_NAME}: {ANSWERS[1]}")
                text_widget.yview(END)
                say(ANSWERS[1])
            elif query.startswith(OPTIONS[2].lower()) or (("floor" in query or "floors" in query) and "college" in query):
                text_widget.insert(END,f"\n\n{AI_NAME}: {ANSWERS[2]}")
                text_widget.yview(END)
                say(ANSWERS[2])
            elif query.startswith(OPTIONS[3].lower()) or ("cafeteria" in query or "cafe" in query or "food" in query or "foods" in query):
                text_widget.insert(END,f"\n\n{AI_NAME}: {ANSWERS[3]}")
                text_widget.yview(END)
                say(ANSWERS[3])
            elif query.startswith(OPTIONS[4].lower()) or ("car" in query and ("parking" in query or "park" in query)):
                text_widget.insert(END,f"\n\n{AI_NAME}: {ANSWERS[4]}")
                text_widget.yview(END)
                say(ANSWERS[4])
            elif query.startswith(OPTIONS[5].lower()) or (("improve" in query or "improvement" in query) and "college" in query):
                text_widget.insert(END,f"\n\n{AI_NAME}: {ANSWERS[5]}")
                text_widget.yview(END)
                say(ANSWERS[5])
            elif query.startswith(OPTIONS[6].lower())  or ("complain" in query or "complaint" in query or "complains" in query):
                text_widget.insert(END,f"\n\n{AI_NAME}: {ANSWERS[6]}")
                text_widget.yview(END)
                say(ANSWERS[6])
            elif (("parking" in query or "park" in query) and "area" in query):
                text_widget.insert(END,f"\n\n{AI_NAME}: {ANSWERS[7]}")
                text_widget.yview(END)
                say(ANSWERS[7])
            elif (("parking" in query or "park" in query) and "smart" in query):
                text_widget.insert(END,f"\n\n{AI_NAME}: {ANSWERS[8]}")
                text_widget.yview(END)
                say(ANSWERS[8])
            elif (("staffroom" in query or "staff" in query or "staff room" in query)):
                text_widget.insert(END,f"\n\n{AI_NAME}: {ANSWERS[9]}")
                text_widget.yview(END)
                say(ANSWERS[9])
            elif (("principle" in query or "principal" in query) and "office" in query):
                text_widget.insert(END,f"\n\n{AI_NAME}: {ANSWERS[10]}")
                text_widget.yview(END)
                say(ANSWERS[10])
            elif ("washroom" in query or "bathroom" in query):
                text_widget.insert(END,f"\n\n{AI_NAME}: {ANSWERS[11]}")
                text_widget.yview(END)
                say(ANSWERS[11])
            elif ("admin office" in query):
                text_widget.insert(END,f"\n\n{AI_NAME}: {ANSWERS[12]}")
                text_widget.yview(END)
                say(ANSWERS[12])
            elif ("class" in query or "classroom" in query or "class room" in query):
                text_widget.insert(END,f"\n\n{AI_NAME}: {ANSWERS[13]}")
                text_widget.yview(END)
                say(ANSWERS[13])
            elif ("person" in query and "help"):
                text_widget.insert(END,f"\n\n{AI_NAME}: {ANSWERS[14]}")
                text_widget.yview(END)
                say(ANSWERS[14])
            elif ("disaster" in query or "alert" in query):
                text_widget.insert(END,f"\n\n{AI_NAME}: {ANSWERS[15]}")
                text_widget.yview(END)
                say(ANSWERS[15])
            elif ("explore" in query and "first" and "floor" in query):
                text_widget.insert(END,f"\n\n{AI_NAME}: {ANSWERS[16]}")
                text_widget.yview(END)
                say(ANSWERS[16])
            elif ("explore" in query and "second" and "floor" in query):
                text_widget.insert(END,f"\n\n{AI_NAME}: {ANSWERS[17]}")
                text_widget.yview(END)
                say(ANSWERS[17])
            elif ("can" in query and "you" and "do" in query and "what" in query):
                text_widget.insert(END,f"\n\n{AI_NAME}: {ANSWERS[18]}")
                text_widget.yview(END)
                say(ANSWERS[18])
            elif ("choose" in query and "major" in query):
                text_widget.insert(END,f"\n\n{AI_NAME}:{ANSWERS[19]}")
                text_widget.yview(END)
                say(ANSWERS[19])
            elif ("calculus" in query):
                text_widget.insert(END,f"\n\n{AI_NAME}: {ANSWERS[20]}")
                text_widget.yview(END)
                say(ANSWERS[20])
            elif ("tution" in query and "fee" in query):
                text_widget.insert(END,f"\n\n{AI_NAME}: {ANSWERS[21]}")
                text_widget.yview(END)
                say(ANSWERS[21])
            elif ("application" in query and "deadline" in query):
                text_widget.insert(END,f"\n\n{AI_NAME}: {ANSWERS[22]}")
                text_widget.yview(END)
                say(ANSWERS[22])
            elif ("financial" in query and "aid" in query):
                text_widget.insert(END,f"\n\n{AI_NAME}: {ANSWERS[23]}")
                text_widget.yview(END)
                say(ANSWERS[23])
            elif ("contact" in query and "admission" in query and "office" in query):
                text_widget.insert(END,f"\n\n{AI_NAME}: {ANSWERS[24]}")
                text_widget.yview(END)
                say(ANSWERS[24])
            elif ("academic" in query and "resource" in query):
                text_widget.insert(END,f"\n\n{AI_NAME}: {ANSWERS[25]}")
                text_widget.yview(END)
                say(ANSWERS[25])
            elif ("extracurricular" in query and "activit" in query):
                text_widget.insert(END,f"\n\n{AI_NAME}: {ANSWERS[26]}")
                text_widget.yview(END)
                say(ANSWERS[26])
            elif ("dormitories" in query):
                text_widget.insert(END,f"\n\n{AI_NAME}: {ANSWERS[27]}")
                text_widget.yview(END)
                say(ANSWERS[27])
            elif ("academic" in query and "program" in query):
                text_widget.insert(END,f"\n\n{AI_NAME}: {ANSWERS[28]}")
                text_widget.yview(END)
                say(ANSWERS[28])
            elif ("academic" in query and "department" in query):
                text_widget.insert(END,f"\n\n{AI_NAME}: {ANSWERS[29]}")
                text_widget.yview(END)
                say(ANSWERS[29])
            elif ("academic" in query and "requirement" in query):
                text_widget.insert(END,f"\n\n{AI_NAME}: {ANSWERS[30]}")
                text_widget.yview(END)
                say(ANSWERS[30])
            else:
                gpt_reply = gpt(query)
                text_widget.insert(END,f"\n\n{AI_NAME}: {gpt_reply}")
                text_widget.yview(END)
                say(gpt_reply)