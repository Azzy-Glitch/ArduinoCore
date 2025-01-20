const btn = document.querySelector('.talk')
const content = document.querySelector('.mainP')

function speak(text) {
    const text_speak = new SpeechSynthesisUtterance(text);

    text_speak.rate = 1;
    text_speak.volume = 1;
    text_speak.pitch = 1;

    window.speechSynthesis.speak(text_speak);
}

function wishMe() {
    var day = new Date();
    var hour = day.getHours();

    if (hour >= 0 && hour < 12) {
        speak("Good Morning Boss...")
    }

    else if (hour > 12 && hour < 17) {
        speak("Good Afternoon Master...")
    }

    else {
        speak("Good Evenining Sir...")
    }

}

window.addEventListener('load', () => {
    speak("Initializing JARVIS..");
    wishMe();
});

const SpeechRecognition = window.SpeechRecognition || window.webkitSpeechRecognition;

const recognition = new SpeechRecognition();

recognition.onresult = (event) => {
    const currentIndex = event.resultIndex;
    const transcript = event.results[currentIndex][0].transcript;
    content.textContent = transcript;
    takeCommand(transcript.toLowerCase());

}

btn.addEventListener('click', () => {
    content.textContent = "Listening...."
    recognition.start();
})

function takeCommand(message) {
        if (message.includes('hey') || message.includes('hello')) {
            speak("Hello Sir, How May I Help You?");
        }
        else if (message.includes("open google")) {
            window.open("https://google.com", "_blank");
            speak("Opening Google...")
        }
        else if (message.includes("open youtube")) {
            window.open("https://youtube.com", "_blank");
            speak("Opening Youtube...")
        }
        else if (message.includes("open facebook")) {
            window.open("https://facebook.com", "_blank");
            speak("Opening Facebook...")
        }

        else if (message.includes('google it') || message.includes('use google') || message.includes('search it')) {
            window.open(`https://www.google.com/search?q=${message.replace(" ", "+")}`, "_blank");
            const finalText = "This is what i found on internet regarding " + message;
            speak(finalText);
        }

        else if (message.includes('wikipedia')) {
            window.open(`https://en.wikipedia.org/wiki/${message.replace("wikipedia", "")}`, "_blank");
            const finalText = "This is what i found on wikipedia regarding " + message;
            speak(finalText);
        }

        else if (message.includes('time')) {
            const time = new Date().toLocaleString(undefined, { hour: "numeric", minute: "numeric" })
            const finalText = time;
            speak(finalText);
        }

        else if (message.includes('date')) {
            const date = new Date().toLocaleString(undefined, { month: "short", day: "numeric" })
            const finalText = date;
            speak(finalText);
        }

        else if (message.includes('calculator')) {
            window.open('Calculator:///')
            const finalText = "Opening Calculator";
            speak(finalText);
        }
        else if (message.includes('introduce') && (message.includes('college'))) {
            speak('Our college is dedicated to providing a nurturing environment for learning and growth. We strive to foster academic excellence, personal development, and a vibrant community')
        }
        else if (message.includes('introduce') && (message.includes('features')  && (message.includes('college')))) {
            speak('Our college provides plenty of smart featuresss including Smart Parking system with automatic lifts. It also provides a smart attendance system build using Javascript. It uses face detection .')
            speak('algorithm to detect the faces to recogize the students')
        }
        else if ((message.includes('facilities') && (message.includes("college"))) || (message.includes("facilities"))){
            speak('Our college offers a range of facilities including classrooms equipped with modern technology, a well-stocked library, laboratory facilities for various disciplines, sports facilities,')
            speak(' a cafeteria, administrative offices, and dormitory accommodations')
        }
        else if(message.includes("floor") && message.includes("college")){
            speak('Ground Floor: Houses administrative offices, the cafeteria, and main entrance.First Floor: Classrooms and academic departments.')
            speak('Second Floor: Additional classrooms, laboratories, and academic resources.')
        }
        else if(message.includes("cafe") || message.includes("food")){
            speak('Our cafeteria provides a variety of delicious and nutritious meals for students and staff, ensuring everyone has access to quality dining options')
        }
        else if(message.includes("car") && message.includes("parking")){
            speak('We have designated parking areas available for students, staff, and visitors. Our smart parking system efficiently manages parking spaces to ensure convenience and ease of access.')
            speak('Park like the future!** College unveils an automatic vertical parking system on the left side')
        }
        else if(message.includes("improve") || message.includes("improvement") && message.includes("college")){
            speak('We welcome any suggestions or feedback on how we can enhance our college environment and services to better meet the needs of our students and community')
        }
        else if(message.includes("complain") || message.includes("complaint")){
            speak('If you have any complaints, please bring them to our attention, and we will address them promptly to ensure your concerns are resolved satisfactorily')
        }
        else if(message.includes("parking") && message.includes("area")){
            speak('Park like the future! College unveils an automatic vertical parking system on the left side.')
        }
        else if(message.includes("smart") && message.includes("parking")){
            speak('We have designated parking areas available for students, staff, and visitors. Our smart parking system efficiently manages parking spaces to ensure convenience and ease of access.')
            speak('')
        }
        else if (message.includes("staffroom")){
            speak('The staffroom is situated on the first floor of the college building.Conveniently located near the Principals office for easy access.Directly opposite to the Principals office ')
        }
        else if(message.includes("principle") && message.includes("office")){
            speak('Conveniently positioned on the ground floor, the Principals office is just steps away from the main entrance, ensuring easy access for all.')
        }
        else if(message.includes("washroom") || message.includes("bathroom")){
            speak('Washrooms are conveniently located on each floor of the college building, with separate facilities for gentlemen and ladies.')
        }
        else if(message.includes("admin") && (message.includes("room") || message.includes("office"))){
            speak('The administrative office is located on the first floor. Once you head up the stairs, turn right and you will find it near the cafeteria')
        }
        else if(message.includes("class")){
            speak('Spread across the first and second floors, our college classrooms offer conducive environments for learning First-year students benefit from dedicated spaces on the first floor')
            speak('while sophomore classes are conveniently located on the second floor.Go! and explore our vibrant learning spaces today!')
        }
        else if(message.includes("person") && message.includes("help")){
            speak('If you require assistance, please feel free to approach any staff member, or visit the administrative office for guidance and support.')
        }
        else if(message.includes("disaster") || message.includes("alert")){
            speak('Our college has measures in place to identify and respond to disasters or emergencies effectively, ensuring the safety and well-being of everyone on campus.')
        }
        else if(message.includes("explore") && message.includes("first") && message.includes("floor")){
            speak('You are welcome to explore the first floor of the college building at your leisure')
        }
        else if(message.includes("explore") && message.includes("second") && message.includes("floor")){
            speak('You are welcome to explore the second floor of the college building at your leisure.')
        }
        else if(message.includes("what") && message.includes("can") && message.includes("you") && message.includes("do")){
            speak('I am your personal college companion! Whether you need help finding resources, managing your schedule, or just need some academic advice, Im here to support you.')
        }
        else if(message.includes("choose") && message.includes("major")){
            speak('We provide guidance and resources to help students choose a major that aligns with their interests, skills, and career goals')
        }
        else if(message.includes("calculus") || message.includes("prerequisites")){
            speak('Prerequisites for courses vary depending on the program of study. Please consult the academic department or advisor for specific information')
        }
        else if(message.includes("tution") && message.includes("fee") || message.includes("dues")){
            speak('The tuition fees for the college are outlined in our official fee schedule, which is available upon request or on our website')
        }
        else if(message.includes("application") && message.includes("deadlines")){
            speak('For information regarding application deadlines, please contact the admissions office for assistance.')
        }
        else if(message.includes("financial") && message.includes("aid")){
            speak('Information on applying for financial aid, including scholarships, grants, and loans, can be obtained from the financial aid office or from the admin office.')
        }
        else if(message.includes("contact") || message.includes("admission") && message.includes("office")){
            speak('You can find contact details for the admissions office on our website or by inquiring at the administrative office.')
        }
        else if(message.includes("academic") && message.includes("resource")){
            speak('Our college offers a wide range of academic resources, including a library stocked with books, journals, online databases, and other learning materials to support students academic endeavors.')
        }
        else if(message.includes("extracurricular") && message.includes("activity"))
        {
            speak('We offer a variety of extracurricular activities, including sports teams, clubs, cultural organizations, and community service opportunities,')
            speak(' to enrich the student experience and promote holistic development.')
        }
        else if(message.includes("dormitories")){
            speak('Our dormitory facilities provide comfortable accommodations for students, offering a supportive living environment conducive to academic success and personal growth')
        }
        else if(message.includes("academic") && message.includes("program")){
            speak('Our college offers diverse academic programs spanning various disciplines, providing students with opportunities for intellectual exploration and professional development.')
        }
        else if(message.includes("academic") && message.includes("department")){
            speak('We have several academic departments, each dedicated to a specific field of study, staffed by experienced faculty members committed to delivering high-quality education and research opportunities.')
        }
        else if(message.includes("academic") && message.includes("requirement")){
            speak('Admission to our college typically requires meeting specific academic requirements, which may include standardized test scores, high school transcripts,')
            speak('and other criteria depending on the program of interest')
        }
        else if(message.includes("programming") && message.includes("college")){
            speak('')
            speak('and other criteria depending on the program of interest')
        }
        else if(message.includes("academic") && message.includes("requirement")){
            speak('Admission to our college typically requires meeting specific academic requirements, which may include standardized test scores, high school transcripts,')
            speak('and other criteria depending on the program of interest')
        }
        else {
            speak("I am confused about what you are saying, can you tell me more about this?  and also remember that I will only answer questions related to Smart College");
        }
    }