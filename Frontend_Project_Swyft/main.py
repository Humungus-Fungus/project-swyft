from kivy.app import App  # This imports the kivy library
from kivy.lang import Builder  # This imports the builder, which is used to cmopile the kvylang code
import ColoredLabels  # extends functionality to allow labels to have color
from kivy.uix.screenmanager import ScreenManager, Screen  # allows the creation of screen and the manager for them
from kivy.uix.textinput import TextInput  # allows input to be taken directly from the UI
from kivy.uix.label import Label  # Allows creating of labels
from kivy.uix.popup import Popup  # Allows creation of popups
from kivy.uix.button import Button  # Allows creation of buttons
from kivy.uix.boxlayout import BoxLayout  # Allows the UI to be arranged using the layout known as 'box layout'
from kivy.uix.floatlayout import FloatLayout  # Allows the UI to be arranged using the layout known as 'float layout'
from kivy.uix.image import Image  # Allows images to be displayed in the UI
from kivy.properties import *  # import all properties, which are used for things like storing input from the UI
from kivy_garden.mapview import MapView, MapMarkerPopup  # Allows maps to be used, and markers to place on them
from kivy.clock import Clock
from datetime import datetime
import pyodbc  # This module is for connecting to my database and extracting data from it/inserting data into it

conn = pyodbc.connect("DRIVER={SQL Server Native Client 11.0};UID=Svangulfur;WSID=COMPUTEROFSVANG;APP={Microsoft® Wind"
                      "ows® Operating System};Trusted_Connection=Yes;SERVER=COMPUTEROFSVANG;Description=tutorial")
cursor = conn.cursor()

# We need to connect to the common folder in order to access the green light timings
# Start node = Home location's Primary key
# Target node is Primary key of location entered by user


# Represents home screen
class HomeScreen(Screen):
    def __init__(self, **kwargs):
        super(HomeScreen, self).__init__(**kwargs)  # Initialisation of the HomeScreen class

        self.get_target_node()

        self.rec_vel = ColoredLabels.LabelB(text="Recommended speed: \n{} km/h".format(15),
                                            pos_hint={"center_x": 0.4275, "top": 1},
                                            size_hint=(0.25, 0.25), bcolor=(0.5, 0.5, 0.75, 1))
        self.time_left = ColoredLabels.LabelB(text="Seconds till red: \n35", pos_hint={"center_x": 0.675, "top": 1},
                                              size_hint=(0.25, 0.25), bcolor=(0.1, 0.1, 0.1, 1))

        # This creates the text input box to enter the destination's name
        self.target_name = TextInput(text="Enter Destination Name", size_hint=(0.3, 0.25),
                                     pos_hint={"left": 1, "top": 1})
        # This creates the button that, when pressed, saves the data in the previously defined text box
        self.enter_target = Button(text="Enter Target", size_hint=(0.3, 0.25), pos_hint={"left": 1, "top": 0.75})
        # Whenever the button is pressed, the method get_target is called
        self.enter_target.bind(on_release=self.get_target)

        self.target = ""

        # Adds the widgets previously declared
        self.add_widget(self.rec_vel)
        self.add_widget(self.time_left)
        self.add_widget(self.target_name)
        self.add_widget(self.enter_target)

        self.init_time = 35  # 35 is a placeholder, it will eventually obtain this value from our database
        self.timer = 0

        # Getting the data for the home location start node
        cursor.execute("SELECT Location_ID FROM Locations, Driver WHERE Location_Name = Driver.Home_Location;")
        home_location = str(cursor.fetchone()[0])

        # NEXT: store this value in the 'start_node.txt' file
        file = open("C:/Users/Svangulfur/PycharmProjects/project-swyft/CommonFolder/start_node.txt", "w")
        file.write(home_location)

    # This method decides what happs after a button is released
    def on_release(self):
        self.update_func = Clock.schedule_interval(self.update, 1)  # Updates the clock by increasing it's value by one,
        # which represents one second passing in real time
        Clock.schedule_once(self.stop, self.init_time+1)  # increments the clock

    # This method changes the value shown on the timer depending on how many seconds have passed
    def update(self, *args):
        self.time_left.text = "Seconds till red:\n" + str(self.init_time - self.timer)  # Displaying the time left
        self.timer += 1  # timer increments
        if self.init_time - self.timer > 2*self.init_time // 3:  # Here, if the timer is greater than 2/3 of it's inital value...
            self.time_left.bcolor = (0, 0.5, 0, 1)  # The timer will be green
        elif self.init_time - self.timer > self.init_time // 3:  # If the time left is greater than 1/3, then...
            self.time_left.bcolor = (1, 0.65, 0, 1)  # The timer turns orange
        elif self.init_time - self.timer < self.init_time // 3:  # If the time left is less than 1/3...
            self.time_left.bcolor = (0.5, 0, 0, 1)  # The timer turns red

    # Stops the timer, to prevent it going below 0
    def stop(self, *args):
        self.update_func.cancel()  # stops the timer

    # Gets the target node as input from the user
    def get_target(self):
        self.target = self.target_name.text  # Takes the input from the input box
        sql_command = "SELECT Location_ID FROM Locations WHERE Location_Name = '{}'".format(self.target)  # This command
        # gets the ID of the location
        cursor.execute(sql_command)  # Executing the aforementioned command
        target_ID = cursor.fetchone()[0]  # Storing the output of the query
        # Opens the target_node.txt file for the backend to know which node is the target node
        target_file = open("C:/Users/Svangulfur/PycharmProjects/project-swyft/CommonFolder/target_node.txt", 'w')
        target_file.write(target_ID)  # Stores the data in the external file

    def get_target_node(self):
        # Init time is the time left before the next light turns red
        green_times_file = open("C:/Users/Svangulfur/PycharmProjects/project-swyft/CommonFolder/GreenTimesForUI.txt",
                                'r')  # Obtaining the values for the green light
        # timings
        now = datetime.now()  # Getting the current time
        time_format = "%H:%M"  # The format of the time we want to look for within GreenTimesForUI.txt
        time = now.strftime(time_format)  # Getting the time right now into that format
        time_values = green_times_file.readlines()  # Storing this data in a local variable
        times = []  # This list will contain all the green light times relevant to the path chosen

        nodes_file = open("C:/Users/Svangulfur/PycharmProjects/project-swyft/CommonFolder/RoadLength.txt")

        lengths = nodes_file.readlines()
        print(lengths)
        print(time_values)
        nodes = len(lengths)
        if '\n' in lengths[0]:
            lengths[0] = lengths[0][0]
        if '\n' in time_values[0]:
            time_values[0] = time_values[0][0]
        print(lengths[0])
        print(time_values[0])
        #self.recommended_speed = int(lengths[0])/int(time_values[2])

        for i in range(len(time_values)):  # For each time value within the file
            if time in time_values[i]:  # If that time is the same as the current time to the nearest minute...
                times = time_values[i:i + nodes]  # That time will be used, along with the times along the way of each
                # traffic light that needs to be crossed
                break




# Represents the screen with the map
class MapScreen(Screen):
    def __init__(self, **kwargs):
        super(MapScreen, self).__init__(**kwargs)  # Initialisation

        self.box_layout = BoxLayout()

        self.map_view = MapView(lat=10, lon=10, zoom=5)  # Adds the map

        self.box_layout.add_widget(self.map_view)


# Represents the screen with all settings
class SettingsScreen(Screen):
    # Initialising the variables
    def __init__(self, **kwargs):
        super(SettingsScreen, self).__init__(**kwargs)  # initialisation

        # This line is the contents variables for which
        content = Button(text="Enter the Model, Fuel Volume in \nLitres, and Fuel "
                              "Efficiency in litres\n per kilometer, in that exact order,\nseparated by a comma and a"
                              " space\n\n     Click to Close")
        self.popup = Popup(title="Add Vehicle", content=content, size_hint=(None, None), size=(300, 200),
                           pos_hint={"center_x": 0.5, "center_y": 0.5})
        content.bind(on_release=self.popup.dismiss)

        content2 = Button(text="No data was entered.\nPress the above button first")
        self.warning = Popup(title="Error", content=content2, size_hint=(None, None), size=(300, 200),
                             pos_hint={"center_x": 0.5, "center_y": 0.5})
        content2.bind(on_release=self.warning.dismiss)

        # This is the location set as the home address. Can be changed at any time
        self.home_loc_inp = TextInput(pos_hint={"left": 1, "top": 0.7}, size_hint=(0.4, 0.1),
                                      text="Enter Home Location", multiline=False)  # Creates a text input box for the
        # home location
        self.new_home_loc = ""  # This will store the new home location entered by the user
        cursor.execute("SELECT Home_Location FROM Driver WHERE Driver_ID = 1")  # Executes this SQL command
        home_loc_text = cursor.fetchone()[0]  # Takes the first value queried from the database
        self.home_loc = ColoredLabels.LabelB(text=home_loc_text, size_hint=(0.2, 0.1),
                                             pos_hint={"right": 0.4, "top": 1}, bcolor=(1, 1, 1, 1),
                                             color=(0, 0, 0, 1))  # Creates the label which holds
        # the home address

        self.username = TextInput(pos_hint={"right": 0.8, "top": 0.7}, size_hint=(0.4, 0.1), text="Enter Name Here")  #
        # This will hold the input of the user's name
        self.new_name = ""  # This will hold the new name the user enters

        self.name_direction = Label(text="Name: ", size_hint=(0.2, 0.1), pos_hint={"right": 0.6, "top": 1})  # Directs
        # the user to where their name is displayed
        cursor.execute("SELECT Driver_Name FROM Driver WHERE Driver_ID = 1")  # Executes this SQL command
        name_text = cursor.fetchone()[0]  # Taking the first result from the previous query
        self.display_name = ColoredLabels.LabelB(text=name_text, size_hint=(0.2, 0.1),
                                                 pos_hint={"right": 0.8, "top": 1}, bcolor=(1, 1, 1, 1),
                                                 color=(0, 0, 0, 1))  # Creating the label which will hold the value of
        # the name

        cursor.execute("SELECT COUNT (*) FROM Vehicles")  # Counts the number of records stored in the Vehicles table
        self.vehicle_count = cursor.fetchone()[0]  # Takes the first result
        self.vehicle_add = Label(text="Vehicles recorded: " + str(self.vehicle_count), pos_hint={"left": 1, "top": 0.6},
                                 size_hint=(0.2, 0.1))  # Label which holds the vehicle count
        self.vehicle_inp = TextInput(pos_hint={"right": 0.4, "top": 0.6}, size_hint=(0.2, 0.1),
                                     text="Enter Details Here")

        self.add_widget(self.home_loc_inp)  # Adds this widget, the input for the home location
        self.add_widget(self.username)  # Adds the text input for the user's name
        self.add_widget(self.display_name)  # Adds the label that shows the user's name
        self.add_widget(self.name_direction)  # Adds the label that directs the user to the name
        self.add_widget(self.home_loc)  # Adds the label that shows the user's home location
        self.add_widget(self.vehicle_add)  # Adds label that shows the number of recorded vehicles owned by the driver

    # This method updates the stored name of the user
    def update_name(self):
        sql_command = "UPDATE Driver SET Driver_Name = '{}' WHERE Driver_ID = 1".format(self.new_name)  # Defining an
        # SQL command
        cursor.execute(sql_command)  # Executing the SQL command from before
        cursor.execute("SELECT Driver_Name FROM Driver WHERE Driver_ID = 1")  # Executes this SQL command
        name_text = cursor.fetchone()[0]  # Takes the first result of the query
        self.display_name.text = name_text  # Updates the name displayed
        conn.commit()  # Saves the changes

    # This method updates the stored home location of the user
    def update_home_loc(self):
        sql_command = "UPDATE Driver SET Home_Location = '{}' WHERE Driver_ID = 1".format(self.new_home_loc)  # Defining
        # an SQL command
        cursor.execute(sql_command)  # Executing the previous SQL command
        cursor.execute("SELECT Home_Location FROM Driver WHERE Driver_ID = 1")  # Executes this SQL command
        home_loc_text = cursor.fetchone()[0]  # Takes the first value queried from the database
        self.home_loc.text = home_loc_text  # Updating the home location to the new value
        conn.commit()  # Saves the changes

    # This method records a new vehicle
    def show_vehicle_add(self):
        self.popup.open()
        self.add_widget(self.vehicle_inp)  # Makes the widget for entering the vehicle details

    def add_vehicle(self):
        try:
            self.remove_widget(self.vehicle_inp)
            sql_command = "INSERT INTO Vehicles VALUES ({}, {})".format(self.vehicle_count+1, self.vehicle_inp.text)  #
            # Creates an SQL command to add the new record into the Vehicles table
            cursor.execute(sql_command)  # Executes this SQL command
            conn.commit()  # Saves the changes
            cursor.execute("SELECT COUNT (*) FROM Vehicles")  # Counts number of records stored in the Vehicles table
            self.vehicle_count = cursor.fetchone()[0]  # Takes the first result
            self.vehicle_add.text = "Vehicles recorded: " + str(self.vehicle_count)
        except pyodbc.ProgrammingError:
            self.warning.open()


# Manages all screens
class WinManager(ScreenManager):
    pass


kv = Builder.load_file("customwidget.kv")  # Builds all kivy code from the customwidgets.kv file


# Class where the app is run
class KivyApp(App):

    def build(self):
        return kv


# runs the program
if __name__ == "__main__":
    KivyApp().run()
