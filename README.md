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
V4.x
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
sudo echo "y" | wee_database --config=/etc/weewx/weewx.conf --add-column=rainDur_2 --type=REAL
sudo echo "y" | wee_database --config=/etc/weewx/weewx.conf --add-column=sunshineDur_2 --type=REAL
sudo echo "y" | wee_database --config=/etc/weewx/weewx.conf --add-column=windGustSpeed10_2 --type=REAL

V5.x
weectl database add-column co2_Temp --type=REAL -y
weectl database add-column co2_Hum --type=REAL -y
weectl database add-column co2_Batt --type=REAL -y
weectl database add-column THSW --type=REAL -y
weectl database add-column THW --type=REAL -y
weectl database add-column windGustSpeed10 --type=REAL -y
weectl database add-column sunshine_hours --type=REAL -y
weectl database add-column sunshine_time --type=REAL -y
weectl database add-column sunshineDur --type=REAL -y
weectl database add-column rainDur --type=REAL -y
weectl database add-column hailDur --type=REAL -y

weectl database add-column outTemp_2 --type=REAL -y
weectl database add-column outHumidity_2 --type=REAL -y
weectl database add-column dewpoint2 --type=REAL -y
weectl database add-column heatindex2 --type=REAL -y
weectl database add-column windchill2 --type=REAL -y
weectl database add-column THSW_2 --type=REAL -y
weectl database add-column THW_2 --type=REAL -y
weectl database add-column outWetbulb_2 --type=REAL -y
weectl database add-column radiation_2 --type=REAL -y
weectl database add-column UV_2 --type=REAL -y
weectl database add-column windSpeed_2 --type=REAL -y
weectl database add-column windDir_2 --type=REAL -y
weectl database add-column windGust_2 --type=REAL -y
weectl database add-column windGustDir_2 --type=REAL -y
weectl database add-column rain_2 --type=REAL -y
weectl database add-column rainRate_2 --type=REAL -y
weectl database add-column xBatteryStatus_2 --type=REAL -y
weectl database add-column rsignal1_2 --type=REAL -y
weectl database add-column rainDur_2 --type=REAL -y
weectl database add-column sunshineDur_2 --type=REAL -y
weectl database add-column windGustSpeed10_2 --type=REAL -y
```
```
# The WLL can get dat from up to eight transmitters. If multiple transmitters e.g. extra ISS for wind, extra temp sensor, requires the lsid_iss
[StdReport]

    [[SeasonsReport]]
        # The SeasonsReport uses the 'Seasons' skin, which contains the
        # images, templates and plots for the report.
        skin = Seasons
        enable = false

    [[SeasonsDavis]]
        # The SeasonsReport uses the 'Seasons' skin, which contains the
        # images, templates and plots for the report.
        skin = SeasonsDavis
        enable = true

    [[AirLinkReport]]
        # The SeasonsReport uses the 'Seasons' skin, which contains the
        # images, templates and plots for the report.
        skin = airlink
        enable = false

    [[DavisHealth]]
        # The SeasonsReport uses the 'Seasons' skin, which contains the
        # images, templates and plots for the report.
        skin = health
        enable = false

[DataBindings]
    
    [[wx_binding]]
        # This is likely to be the only option you would want to change.
        database = daviswll_sqlite
        table_name = archive
        manager = weewx.manager.DaySummaryManager
        schema = schemas.wview_extendedmy.schema
        #schema = schemas.wview_extended2my.schema	#use this if a second ISS/VUE is available

    [[davishealthapi_binding]]
        database = davishealthapi_sqlite
        table_name = archive
        manager = weewx.manager.DaySummaryManager
        schema = user.davishealthapi.schema		#is generated by the driver
    [[davisconsolehealthapi_binding]]
        database = davisconsolehealthapi_sqlite
        table_name = archive
        manager = weewx.manager.DaySummaryManager
        schema = user.davisconsolehealthapi.schema	#is generated by the driver

[Databases]
    
    [[daviswll_sqlite]]
        database_name = daviswll.sdb
        database_type = SQLite
    [[davishealthapi_sqlite]]
        database_type = SQLite
        database_name = davishealthapi.sdb
    [[davisconsolehealthapi_sqlite]]
        database_type = SQLite
        database_name = davisconsolehealthapi.sdb

[Engine]
    # The following section specifies which services should be run and in what order.
    [[Services]]
        prep_services = weewx.engine.StdTimeSynch
        #data_services = user.davishealthapi.DavisHealthAPI,
        #data_services = user.airlink.AirLink, user.davishealthapi.DavisHealthAPI,
        data_services = user.airlink.AirLink, user.davishealthapi.DavisHealthAPI,
        process_services = weewx.engine.StdConvert, weewx.engine.StdCalibrate, weewx.engine.StdQC, weewx.wxservices.StdWXCalculate, user.sunrainduration.SunshineDuration, user.radiationhours.RadiationHours
        # process_services = weewx.engine.StdConvert, weewx.engine.StdCalibrate, weewx.engine.StdQC, weewx.wxservices.StdWXCalculate, user.sunduration.SunshineDuration, user.radiationhours.RadiationHours
        # xtype_services = weewx.wxxtypes.StdWXXTypes, weewx.wxxtypes.StdPressureCooker, weewx.wxxtypes.StdRainRater, weewx.wxxtypes.StdDelta
        # xtype_services = weewx.wxxtypes.StdWXXTypes, weewx.wxxtypes.StdPressureCooker, weewx.wxxtypes.StdRainRater, weewx.wxxtypes.StdDelta, user.GTS.GTSService
        xtype_services = weewx.wxxtypes.StdWXXTypes, weewx.wxxtypes.StdPressureCooker, weewx.wxxtypes.StdRainRater, weewx.wxxtypes.StdDelta
        # xtype_services = weewx.wxxtypes.StdWXXTypes, weewx.wxxtypes.StdDelta
        # xtype_services = weewx.wxxtypes.StdWXXTypes, weewx.wxxtypes.StdPressureCooker, weewx.wxxtypes.StdRainRater, weewx.wxxtypes.StdDelta
        archive_services = weewx.engine.StdArchive
        restful_services = weewx.restx.StdStationRegistry
        # restful_services = weewx.restx.StdStationRegistry, weewx.restx.StdWunderground, weewx.restx.StdPWSweather, weewx.restx.StdCWOP, weewx.restx.StdWOW, weewx.restx.StdAWEKAS, user.meteoservices.Meteoservices
        report_services = weewx.engine.StdPrint, weewx.engine.StdReport

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


[AirLink]
    [[Sensor1]]
        enable = False
        hostname = 192.168.0.124
        port = 80
        timeout = 4
        wait_before_retry = 15
        #max_tries = 2

    [[Sensor2]]
        enable = False
        hostname = airlink2
        port = 80
        timeout = 2

[davishealthapi]
    data_binding = davishealthapi_binding
    station_id = 125550
    #station_id = 70122
    packet_log = 0
    max_count = 13
    #max_ccount = 13
    max_age = None
    api_key = uuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuu
    api_secret = vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
    sensor_tx1 = 4
    sensor_tx2 = 1
    sensor_tx3 = 2
    sensor_tx4 = 7
    sensor_tx5 = 8
    sensor_tx6 = 0
    sensor_tx7 = 0
    sensor_tx8 = 0

[davisconsolehealthapi]
    data_binding = davisconsolehealthapi_binding
    station_id = 156589
    packet_log = 0
    max_count = 13
    max_age = None
    api_key = uuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuu
    api_secret = vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv

[RadiationDays]
    min_sunshine = 120
    sunshine_log = 0
    sunshine_coeff = 0.92
    sunshine_min = 18

    rain2 = 0
    sunshine2 = 0    
    sunshine2_loop = 1
    rainDur2_loop = 0
    sunshine2_log = 0
    rainDur2_log = 0

```
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
