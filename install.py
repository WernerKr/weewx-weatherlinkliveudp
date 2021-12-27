# Installer file for WeatherLink Live (WeatherLinkLiveUDP) driver for WeeWX
# Copyright 2020 Bastiaan Meelberg
# Modified 2021 Werner Krenn (leaf/soil/Extra2..4,Wind,Rain)
# Distributed under the terms of the GNU Public License (GPLv3)

from setup import ExtensionInstaller

def loader():
    return weatherlinkliveudpInstaller()

class weatherlinkliveudpInstaller(ExtensionInstaller):
    def __init__(self):
        super(weatherlinkliveudpInstaller, self).__init__(
            version='0.4.0',
            name='WeatherLinkLiveUDP',
            description='Periodically poll weather data from a WeatherLink Live device',
            author="Bastiaan Meelberg, Werner Krenn",
            config={
                'WeatherLinkLiveUDP': {
                    'wll_ip': '1.2.3.4',
                    'poll_interval': 30,
                    'driver': 'user.weatherlinkliveudp',
                    '#txid_iss' : 1,
                    '#extra_id': 2,
                    '#extra_id2': 0,
                    '#extra_id3': 0,
                    '#extra_id4': 0,
                    '#leaf': 0,
                    '#soil': 0,
                    '#wind': 0,
                    '#txid_rain': 0,
                    '#did': '001D0A61F5E8',
                    'log': 0,
                }
            },
            files=[('bin/user', ['bin/user/weatherlinkliveudp.py'])]

        )
