# This module is for connecting to my database and extracting data from it/inserting data into it
import pyodbc
import speech_recognition as sr

conn = pyodbc.connect(
    "DRIVER={SQL Server Native Client 11.0};UID=Svangulfur;WSID=COMPUTEROFSVANG;APP={Microsoft® Windows® Operating Syste"
    "m};Trusted_Connection=Yes;SERVER=COMPUTEROFSVANG;Description=tutorial")
cursor = conn.cursor()

string_voice = ""  # This will hold the input of the user's voice as a string

r = sr.Recognizer()  # Creating a new recognizer object

mic = sr.Microphone()

with mic as source:
    r.adjust_for_ambient_noise(source, duration=2) # This adjusts for any noises in the background
    print("Analysis done! Start talking")
    audio = r.listen(source)
    print("Processing...")

try:
    string_voice = r.recognize_sphinx(audio)  # Here, sphinx is used because it works offline
    print(string_voice)
    if "home" in string_voice and 'n' in string_voice:
        cursor.execute("SELECT Home_Location FROM Driver WHERE Driver_ID = 1")
        result = cursor.fetchone()[0]
        print("Home is " + result)
    else:
        raise sr.UnknownValueError
except sr.UnknownValueError:
    print("Sorry, could you repeat that?")
