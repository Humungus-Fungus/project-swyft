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
from kivy.properties import *  # import all properties, which are used for things like storing input from the UI
from kivy_garden.mapview import MapView, MapMarkerPopup  # Allows maps to be used, and markers to place on them
from kivy.clock import Clock


# Represents home screen
class HomeScreen(Screen):
    def __init__(self, **kwargs):
        super(HomeScreen, self).__init__(**kwargs)  # Initialisation of the HomeScreen class
        # Labels to store the latitude and longitude
        self.rec_vel = ColoredLabels.LabelB(text="Recommended speed: \n15 km/h", pos_hint={"center_x": 0.4275, "top": 1},
                                            size_hint=(0.25, 0.25), bcolor=(0.5, 0.5, 0.75, 1))
        self.time_left = ColoredLabels.LabelB(text="Seconds till red: \n35", pos_hint={"center_x": 0.675, "top": 1}, size_hint=(0.25, 0.25),
                                              bcolor=(0.1, 0.1, 0.1, 1))

        # Adds the widgets previously declared
        self.add_widget(self.rec_vel)
        self.add_widget(self.time_left)

        # Init time is the time left before the next light turns red
        self.init_time = 35  # 35 is a placeholder, it will eventually obtain this value from our database
        self.timer = 0

    def on_release(self):
        self.update_func = Clock.schedule_interval(self.update, 1)
        Clock.schedule_once(self.stop, self.init_time+1)

    def update(self, *args):
        self.time_left.text = "Seconds till red:\n" + str(self.init_time - self.timer)
        self.timer += 1
        if self.init_time - self.timer > 2*self.init_time // 3:
            self.time_left.bcolor = (0, 0.5, 0, 1)
        elif self.init_time - self.timer > self.init_time // 3:
            self.time_left.bcolor = (1, 0.65, 0, 1)
        elif self.init_time - self.timer < self.init_time // 3:
            self.time_left.bcolor = (0.5, 0, 0, 1)

    def stop(self, *args):
        self.update_func.cancel()


# Represents the screen with the map
class MapScreen(Screen):
    def __init__(self, **kwargs):
        super(MapScreen, self).__init__(**kwargs)  # Initialisation

        self.box_layout = BoxLayout()

        self.map_view = MapView(lat=10, lon=10, zoom=5)  # Adds the map

        self.box_layout.add_widget(self.map_view)


# Represents the screen with all settings
class SettingsScreen(Screen):
    def __init__(self, **kwargs):
        super(SettingsScreen, self).__init__(**kwargs)  # initialisation

        # This is the location set as the home address. Can be changed at any time
        self.home_loc_inp = TextInput(pos_hint={"left": 1, "top": 0.7}, size_hint=(0.4, 0.1), text="New home loc",
                                      multiline=False)
        self.info = Image(pos_hint={"right": 1, "top": 0.98}, size_hint=(0.2, 0.2), source="ImageResources/InfoButton.png")
        self.add_widget(self.home_loc_inp)  # Adds this widget
        self.add_widget(self.info)


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
