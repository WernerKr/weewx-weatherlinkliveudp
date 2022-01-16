# WeatherLinkLiveUDP
Weewx Driver for The WeatherLink Live (WLL). It implements a HTTP interface for getting current weather data and can support continuous requests as often as every 10 seconds.
Also it collects a real-time 2.5 sec broadcast for wind speed and rain over UDP port 22222.
More information on the Davis Intruments website: [See Davis weatherlink-live-local-api](https://weatherlink.github.io/weatherlink-live-local-api/)

To see a live demo of this plugin in vist [pc-wetterstation.de/weewx](https://www.pc-wetterstation.de/wetter/weewx), it features the [Belchertown weewx skin](https://github.com/poblabs/weewx-belchertown#belchertown-weewx-skin) from [Pat O'Brien](https://github.com/poblabs).

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
# Supports now a second ISS or VUE (txid_iss2 = x) with this values:
outTemp_2
outHumidity_2
dewpoint2
heatindex2
windchill2
THSW_2
THW_2
outWetbulb_2
radiation_2
UV_2
windSpeed_2
windDir_2
windGust_2
windGustDir_2
windSpeed1_2
windDir1_2
windSpeed10_2
windDir10_2
windGustSpeed10_2
windGustDir10_2
rain_2
rainRate_2
stormRain_2
stormRainlast_2
rain15_2
rain60_2
rain24_2
dayRain_2
monthRain_2
yearRain_2
rain_rate_hi_last_15_min_2
rainfall_last_24_hr_2
rain_storm_start_at_2
rain_storm_last_start_at_2
rain_storm_last_end_at_2
txBatteryStatus_2
signal1_2
```

```
# If you would like to expand your database schema with this data:
sudo echo "y" | wee_database --config=/etc/weewx/weewx.conf --add-column=outTemp_2 --type=REAL
sudo echo "y" | wee_database --config=/etc/weewx/weewx.conf --add-column=outHumidity_2 --type=REAL
sudo echo "y" | wee_database --config=/etc/weewx/weewx.conf --add-column=dewpoint2 --type=REAL
sudo echo "y" | wee_database --config=/etc/weewx/weewx.conf --add-column=heatindex2 --type=REAL
sudo echo "y" | wee_database --config=/etc/weewx/weewx.conf --add-column=windchill2 --type=REAL
sudo echo "y" | wee_database --config=/etc/weewx/weewx.conf --add-column=THSW_2 --type=REAL
sudo echo "y" | wee_database --config=/etc/weewx/weewx.conf --add-column=THW_2 --type=REAL
sudo echo "y" | wee_database --config=/etc/weewx/weewx.conf --add-column=outWetbulb_2 --type=REAL
sudo echo "y" | wee_database --config=/etc/weewx/weewx.conf --add-column=radiation_2 --type=REAL
sudo echo "y" | wee_database --config=/etc/weewx/weewx.conf --add-column=UV_2 --type=REAL
sudo echo "y" | wee_database --config=/etc/weewx/weewx.conf --add-column=windSpeed_2 --type=REAL
sudo echo "y" | wee_database --config=/etc/weewx/weewx.conf --add-column=windDir_2 --type=REAL
sudo echo "y" | wee_database --config=/etc/weewx/weewx.conf --add-column=windGust_2 --type=REAL
sudo echo "y" | wee_database --config=/etc/weewx/weewx.conf --add-column=windGustDir_2 --type=REAL
sudo echo "y" | wee_database --config=/etc/weewx/weewx.conf --add-column=rain_2 --type=REAL
sudo echo "y" | wee_database --config=/etc/weewx/weewx.conf --add-column=rainRate_2 --type=REAL
sudo echo "y" | wee_database --config=/etc/weewx/weewx.conf --add-column=xBatteryStatus_2 --type=REAL
sudo echo "y" | wee_database --config=/etc/weewx/weewx.conf --add-column=rsignal1_2 --type=REAL
```
```
# The WLL can get dat from up to eight transmitters. If multiple transmitters e.g. extra ISS for wind, extra temp sensor, requires the lsid_iss
[WeatherLinkLiveUDP]
    wll_ip = 1.2.3.4
    poll_interval = 10              # number of seconds [minimal 10 sec.]
    driver = user.weatherlinkliveudp
     #txid_iss = 1                  # if not set - as here,  the txid_id for a ISS or VUE is automatical detected 
     #extra_id = 2
     #extra_id2 = None
     #extra_id3 = None
     #extra_id4 = None
                                    #one leaf_soil station is automatical detected
     #leaf = None                   #only leaf station
     #soil = None                   #only soil station
     #wind = None
     #txid_rain = None
     #txid_iss2 = None
     #did = 001D0A61F5E8           #MAC-Adresse of the Live - is needed, if more then one DAVIS stations reports at port 22222
     log = 0                       #internal log-level: 1=UDP check time, 2=only archive-packets, 3=all packets, 4=iss, 5=extra_data1..4, 6=Wind,Rain, 7=ISS2, 8=iss_udp, 9=all reception


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
or use pip
```
pip install requests
```
