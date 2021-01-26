from kivy.app import App
from kivy.lang import Builder
import ColoredLabels
from kivy.uix.screenmanager import ScreenManager, Screen
from kivy.uix.textinput import TextInput
from kivy.uix.popup import Popup
from kivy.uix.boxlayout import BoxLayout
from kivy.uix.floatlayout import FloatLayout
from kivy.uix.image import Image
from kivy.properties import ObjectProperty, NumericProperty, StringProperty
from kivy_garden.mapview import MapView
import re


class HomeScreen(Screen):
    destination_input = ObjectProperty()
    destination = StringProperty('')
    latitude = NumericProperty(0)
    longitude = NumericProperty(0)

    def enter_dest(self):
        # Assuming the input is the exact coordinate
        pattern = r"\((\d+), (\d+)\)"
        matches = re.search(pattern, self.destination_input.text)

        try:
            latitude, longitude = matches.group(1), matches.group(2)
            print("lat: " + latitude)
            print("lon: " + longitude)
        except AttributeError:
            # Assuming the input is the node number
            self.destination = self.destination_input.text
            print("Got the dest: {}".format(self.destination))


# Represents the screen with the map
class MapScreen(Screen):
    pass


# Contents of the popup
class PopUpDesign(FloatLayout):
    pass


# Represents the screen with all settings
class SettingsScreen(Screen):
    home_loc = NumericProperty(0)

    def change_home_loc(self):
        popup_contents = PopUpDesign()
        self.popup = Popup(title="New Home Loc", contents=popup_contents, size_hint=(0.4, 0.4))
        self.popup.open()

    def close_popup(self):
        self.popup.dismiss()


# Manager all screens
class WinManager(ScreenManager):
    pass


kv = Builder.load_file("customwidget.kv")


class KivyApp(App):

    def build(self):
        return kv


KivyApp().run()
