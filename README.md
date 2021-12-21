# WeatherLinkLiveUDP
Weewx Driver for The WeatherLink Live (WLL). It implements a HTTP interface for getting current weather data and can support continuous requests as often as every 10 seconds.
Also it collects a real-time 2.5 sec broadcast for wind speed and rain over UDP port 22222.
More information on the Davis Intruments website: [See Davis weatherlink-live-local-api](https://weatherlink.github.io/weatherlink-live-local-api/)

To see a live demo of this plugin in vist [meteo-otterlo.nl](https://meteo-otterlo.nl), it features the [Belchertown weewx skin](https://github.com/poblabs/weewx-belchertown#belchertown-weewx-skin) from [Pat O'Brien](https://github.com/poblabs) with a MQTT broker to display the 2.5 seconds wind and rain data.

### Installation


1) Download the driver


2) Install the driver

```
sudo wee_extension --install weatherlinkliveudp.zip
``` 

4) Set the `station_type` to `WeatherLinkLiveUDP` and modify the `[WeatherLinkLiveUDP]` stanza in `weewx.conf`.
```
[Station]

    # Set the type of station.
    station_type = WeatherLinkLiveUDP
```
If you have a separate wind transmitter, set up according to Davis Instruments recommendations: 
[How do I setup the weather link live to use a separate wind transmitter]
(https://support.davisinstruments.com/article/88ogxjf2mm-how-do-i-setup-the-weather-link-live-to-use-a-separate-wind-transmitter).
Where `wll_ip = 1.2.3.4` is the ip address of the WLL.
For logging extra senors just add the transition id to the stanza by adding e.g. `extra_id = x`, 
where x is the id. 
```
# The WLL can get dat from up to eight transmitters. If multiple transmitters e.g. extra ISS for wind, extra temp sensor, requires the lsid_iss
[WeatherLinkLiveUDP]
    wll_ip = 1.2.3.4
    poll_interval = 10              # number of seconds [minimal 10 sec.]
    driver = user.weatherlinkliveudp
     #txid_iss = 1		# if not set - as here,  the txid_id for a ISS or VUE is automatical detected 
     #extra_id = 2
     #extra_id2 = 0
     #extra_id3 = 0
     #extra_id4 = 0
                                    #one leaf_soil station is automatical detected
     #leaf = 0		#only leaf station
     #soil = 0		#only soil station
     #wind = 0
     #txid_rain = 0


4) Restart WeeWX

```
sudo systemctl stop weewx
sudo systemctl start weewx
```

Note: The driver requires the Python `requests` library. To install it:

```
sudo apt-get update 
sudo apt-get install python-requests
```
or us pip
```
pip install requests
```
