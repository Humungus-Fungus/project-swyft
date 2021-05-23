from kivy.app import App  # This imports the kivy library
from kivy.lang import Builder  # This imports the builder, which is used to cmopile the kvylang code
import ColoredLabels  # extends functionality to allow labels to have color
from kivy.uix.screenmanager import ScreenManager, Screen  # allows the creation of screen and the manager for them
from kivy.uix.textinput import TextInput  # allows input to be taken directly from the UI
from kivy.uix.label import Label  # Allows creating of labels
from kivy.uix.popup import Popup  # Allows creation of popups
from kivy.uix.boxlayout import BoxLayout  # Allows the UI to be arranged using the layout known as 'box layout'
from kivy.uix.floatlayout import FloatLayout  # Allows the UI to be arranged using the layout known as 'float layout'
from kivy.uix.image import Image  # Allows images to be displayed in the UI
from kivy.properties import * # import all properties, which are used for things like storing input from the UI
from kivy_garden.mapview import MapView, MapMarkerPopup # Allows maps to be used, and markers to place on them


# Represents home screen
class HomeScreen(Screen):
    def __init__(self, **kwargs):
        super(HomeScreen, self).__init__(**kwargs)  # Initialisation of the HomeScreen class

        # The input for the latitude and longitude
        self.lat_inp = TextInput(text="10", pos_hint={"center_x": 0.425, "top": 1}, size_hint=(0.25, 0.125), multiline=False)
        self.lon_inp = TextInput(text="10", pos_hint={"center_x": 0.675, "top": 1}, size_hint=(0.25, 0.125), multiline=False)

        # Labels to store the latitude and longitude
        self.lat_label = Label(text=self.lat_inp.text, pos_hint={"center_x": 0.425, "top": 0.875}, size_hint=(0.25, 0.125))
        self.lon_label = Label(text=self.lat_inp.text, pos_hint={"center_x": 0.625, "top": 0.875}, size_hint=(0.25, 0.125))

        # Adds the widgets previously declared
        self.add_widget(self.lat_inp)
        self.add_widget(self.lon_inp)
        self.add_widget(self.lat_label)
        self.add_widget(self.lon_label)


# Represents the screen with the map
class MapScreen(Screen):
    def __init__(self, **kwargs):
        super(MapScreen, self).__init__(**kwargs) # Initialisation
        self.map_view = MapView(lat=10, lon=10, zoom=5) # Adds the map
        self.var_lat = 0  # stores the latitude
        self.var_lon = 0  # stored the longitude

    def update(self):  # Updates the variables to the new latitude and longitude values
        self.var_lat = float(HomeScreen().lat_label.text)
        self.var_lon = float(HomeScreen().lon_label.text)
        print(str(self.var_lat) + " and " + str(self.var_lon))


# Represents the screen with all settings
class SettingsScreen(Screen):
    def __init__(self, **kwargs):
        super(SettingsScreen, self).__init__(**kwargs)  # initialisation

        # This is the location set as the home address. Can be changed at any time
        self.home_loc_inp = TextInput(pos_hint={"left": 1, "top": 0.8}, size_hint=(0.4, 0.1), text="New home loc",
                                      multiline=False)
        self.add_widget(self.home_loc_inp)  # Adds this widget


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
