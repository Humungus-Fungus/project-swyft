import speech_recognition as sr

string_voice = ""

r = sr.Recognizer()  # Creating a new recognizer object

# mic = sr.Microphone() # Uses microphone for capturing audio input
harvard = sr.AudioFile('harvard.wav')
with harvard as source:
    # print("Shush!")
    # r.adjust_for_ambient_noise(source, duration=2) # This adjusts for any noises in the background
    # print("Analysis done! Start talking")
    # audio = r.listen(source)
    # print("Processing...")

    audio = r.record(source)

try:
    string_voice = r.recognize_sphinx(audio)  # Here, sphinx is used because it works offline
    print(string_voice)
except sr.UnknownValueError:
    print("Technical difficulties...")

# Next steps:
# Check what string_text is closest to, to make commands
