## summary statistics module for weewx skins
## Copyright Tom Keffer, Matthew Wall
## See LICENSE.txt for your rights
#errorCatcher Echo
#encoding UTF-8

#set $allways_lang = False
#set $use_lang = False
#try
 #if $SKIN_VERSION != '' or $allways_lang == True
  #set $use_lang = True
 #end if
#except
 #pass
#end try


#set $archive_data = [('day', $day), ('week', $week), ('month', $month), ('year', $year), ('alltime', $alltime)]

#set $ecowitt_hw = [('GW1000'),
                    ('GW1100'),
                    ('WH2650'),
                    ('WH2680'),
                    ('WS1900'),
                    ('HP2550'),
                    ('ecowitt-client'),
                    ]

##set $observations = ['outTemp', 'heatindex', 'windchill', 'dewpoint', 'outHumidity', 'barometer', 'rain', 'rainRate', 'ET', 'hail', 'hailRate', 'snow', 'wind', 'UV', 'radiation', 'inTemp', 'inHumidity', 'extraTemp1', 'extraHumid1', 'extraTemp2', 'extraHumid2', 'extraTemp3', 'extraHumid3', 'extraTemp4', 'extraHumid4', 'extraTemp5', 'extraHumid5', 'extraTemp6', 'extraHumid6', 'extraTemp7', 'extraHumid7', 'extraTemp8', 'extraHumid8', 'leafTemp1', 'leafTemp2', 'leafWet1', 'leafWet2', 'soilTemp1', 'soilTemp2', 'soilTemp3', 'soilTemp4', 'soilMoist1', 'soilMoist2', 'soilMoist3', 'soilMoist4', 'pm1_0', 'pm2_5', 'pm10_0', 'co', 'co2', 'nh3', 'no2', 'o3', 'so2']

## The list of observations determines which database fields will be shown in
## the summary as well as the order in which they will be displayed.
#set $observ = [('outTemp','#e85d0d','','1'),
('heatindex','#b44242','','1'),
('windchill','#4282b4','','1'),
('dewpoint','#ea4c12','','1'),
('dewpoint1','','','0'),
('outHumidity','#82dbf2','','1'),
('appTemp','','','0'),
('appTemp1','','','0'),
('heatindex','','','0'),
('heatindex1','','','0'),
('humidex','','','0'),
('humidex1','','','0'),
('barometer','#25ea2f','','1'),
('windSpeed','#0000ff','','1'),
('windavg','#0000ff','','1'),
('windrms','#0000ff','','1'),
('windvecavg','','','1'),
('windGust','#4282b4','','1'),
('wind','#4282b4','','1'),
('windrun','','sum','1'),
('rain','#72b2c4','sum','1'),
('rainRate','#72b2c4','max','1'),
('UV','#E238EC','max','1'),
('ET','#42B4B4','sum','1'),
('hail','','sum','1'),
('hailRate','','max','1'),
('snow','','sum','1'),
('snowRate','','max','1'),
('radiation','#f2a265','max','1'),
('luminosity','','max','0'),
('co2','#32e5d9','','1'),
('co2_Temp','#f20e3c','','1'),
('co2_Hum','#0e25f2','','1'),
('pm1_0','','','1'),
('pm2_5','#0e25f2','','1'),
('pm10_0','#0e25f2','','1'),
('pm25_1','#0e25f2','','1'),
('pm25_2','#0e25f2','','1'),
('pm25_3','#0e25f2','','1'),
('pm25_4','#0e25f2','','1'),
('inTemp','#c95716','','1'),
('inHumidity','#17c4ef','','1'),
('extraTemp1','#e85d0d','','1'),
('extraHumid1','#e85d0d','','1'),
('extraTemp2','#1a50bc','','1'),
('extraHumid2','#1a50bc','','1'),
('extraTemp3','#b44242','','1'),
('extraHumid3','#b44242','','1'),
('extraTemp4','#42B4B4','','1'),
('extraHumid4','#42B4B4','','1'),
('extraTemp5','#b442b4','','1'),
('extraHumid5','#b442b4','','1'),
('extraTemp6','#0000ff','','1'),
('extraHumid6','#0000ff','','1'),
('extraTemp7','#f90415','','1'),
('extraHumid7','#f90415','','1'),
('extraTemp8','#5127db','','1'),
('extraHumid8','#5127db','','1'),
('soilTemp1','#4282b4','','1'),
('soilTemp2','#b44242','','1'),
('soilTemp3','#42b442','','1'),
('soilTemp4','#42b4b4','','1'),
('soilTemp5','#42b4b4','','1'),
('soilTemp6','#42b4b4','','1'),
('soilTemp7','#42b4b4','','1'),
('soilTemp8','#42b4b4','','1'),
('soilMoist1','#e85d0d','','1'),
('soilMoist2','#1a50bc','','1'),
('soilMoist3','#b44242','','1'),
('soilMoist4','#42B4B4','','1'),
('soilMoist5','#b442b4','','1'),
('soilMoist6','#0000ff','','1'),
('soilMoist7','#f90415','','1'),
('soilMoist8','#5127db','','1'),
('leafTemp1','#5427db','','1'),
('leafTemp2','#e85d0d','','1'),
('leafTemp3','#e85d0d','','1'),
('leafTemp4','#e85d0d','','1'),
('leafWet1','#5127db','','1'),
('leafWet2','#5127db','','1'),
('leafWet3','#5127db','','1'),
('leafWet4','#5127db','','1'),
('leafWet5','#5127db','','1'),
('leafWet6','#5127db','','1'),
('leafWet7','#5127db','','1'),
('leafWet8','#5127db','','1'),
('leak_1','#006eff','','1'),
('leak_2','#006eff','','1'),
('leak_3','#006eff','','1'),
('leak_4','#006eff','','1'),
('pb','','','1'),
('co','','','1'),
('nh3','','','1'),
('no2','','','1'),
('o3','','','1'),
('so2','','','1'),
('noise','','','1'),
('lightning_strike_count','','max','1'),
('lightning_energy','','max','1'),
('lightning_noise_count','','max','1'),
]


#set $usefontcolor = 1
#set $ecowitt = 0
#for $x in $ecowitt_hw
  #if $x in $station.hardware
        #set $ecowitt = 1
  #end if
#end for
##

<div id='hilo_widget' class="widget">
  <div class="widget_title">
   #if '4.6' not in $station.version
    <a href="statistics.html">Statistics</a>
   #else
    <a href="statistics.html">$gettext("Statistics")</a>
   #end if
    <a class="widget_control"
      onclick="toggle_widget('hilo')">&diams;</a>
  </div>

  <div class="widget_contents">
  <table>
    <tbody>
      <tr>
        <td></td>
        #if not $use_lang
          <th>&nbsp;<br/>Today</th>
          <th class="hilo_week">&nbsp;<br/>Week</th>
          <th class="hilo_month">&nbsp;<br/>Month</th>
          <th class="hilo_year">&nbsp;<br/>Year</th>
          <th class="hilo_alltime">&nbsp;<br/>Alltime</th> 
          ##<th class="hilo_year">
          ##<a onclick="toggle_rainyear()">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<br/>Year</a>
          ##</th>
          ##<th class="hilo_rainyear">
          ## <a onclick="toggle_rainyear()">Rain<br/>Year</a>
          ##</th>
        #else 
          <th>&nbsp;<br/>$gettext("Today")</th>
          <th class="hilo_week">&nbsp;<br/>$gettext("Week")</th>
          <th class="hilo_month">&nbsp;<br/>$gettext("Month")</th>
          <th class="hilo_alltime">&nbsp;<br/>$gettext("Year")</th>
          <th class="hilo_alltime">&nbsp;<br/>$gettext("Alltime")</th>
          ##<th class="hilo_year">
          ##  <a onclick="toggle_rainyear()">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<br/>$gettext("Year")</a>
          ##</th>
          ##<th class="hilo_rainyear">
          ## <a onclick="toggle_rainyear()">$gettext("Rain<br/>Year")</a>
          ##</th>
        #end if 
        <td></td>
      </tr>

#for $x in $observ
  #for $archive in $archive_data
     #set $check = $archive[1]
  #end for
  #if $x[3] == '1' and (($getattr($day, $x[0]).has_data) or ($day.wind.has_data and ($x[0] == 'windavg' or $x[0] == 'windrms' or $x[0] == 'windrms' or $x[0] == 'windvecavg')))
    #if $usefontcolor == 1
      #set $color = $x[1]
      #if $color == ''
        #set $color = 'black'
      #end if 
    #else
      #set $color = 'black'
    #end if

    #if $x[0] == 'wind'
      <tr>
        <td class="label"><font color=$color>
        #if not $use_lang
          Max Wind
        #else 
          $gettext("Max Wind")
        #end if 
        </font></td>
        #for $archive in $archive_data
        <td class="data new_row hilo_$archive[0]">
          <span title="$archive[1].wind.maxtime">
            $archive[1].wind.max.format(add_label=False)</span><br/>
          $archive[1].wind.gustdir.ordinal_compass $archive[1].wind.gustdir.format(add_label=False)
        </td>
        #end for
        <td class="units">
          $unit.label.wind<br/>
          $unit.label.windDir
        </td>
      </tr>
    #elif $x[0] == 'windavg'  
      <tr>
        <td class="label"><font color=$color>
        #if not $use_lang
          Average Wind
        #else 
          $gettext("Average Wind")
        #end if
        </font></td>
        #for $archive in $archive_data
        <td class="data new_row hilo_$archive[0]">
          $archive[1].wind.avg.format(add_label=False)<br/>
          $archive[1].windDir.avg.ordinal_compass $archive[1].windDir.avg.format(add_label=False)
        #end for
        <td class="units">$unit.label.wind</td>
      </tr>
    #elif $x[0] == 'windrms'      
      <tr>
        <td class="label"><font color=$color>
        #if not $use_lang
          RMS Wind
        #else 
          $gettext("RMS Wind")
        #end if
        </font></td>
        #for $archive in $archive_data
        <td class="data new_row hilo_$archive[0]">
          $archive[1].wind.rms.format(add_label=False)</td>
        #end for
        <td class="units">$unit.label.wind</td>
      </tr>
    #elif $x[0] == 'windvecavg'
      <tr>
        <td class="label"><font color=$color>
        #if not $use_lang
          Vector Average<br/>
          Vector Direction
         #else 
          $gettext("Vector Average")<br/>
          $gettext("Vector Direction")
        #end if
        </font></td>
        #for $archive in $archive_data
        <td class="data new_row hilo_$archive[0]">
          $archive[1].wind.vecavg.format(add_label=False)<br/>
          $archive[1].wind.vecdir.ordinal_compass $archive[1].wind.vecdir.format(add_label=False)
        </td>
        #end for
        <td class="units">
          $unit.label.wind<br/>
          $unit.label.windDir
        </td>
      </tr>
    #else
      <tr>
        <td class="label"><font color=$color>$obs.label[$x[0]]</font></td>
      #if $x[2] == 'sum'
        #for $archive in $archive_data
        <td class="data new_row hilo_$archive[0]">
          #set $xv = $getattr($archive[1], $x[0])
          $xv.sum.format(add_label=False)</td>
        #end for
      #elif $x[2] == 'max'
        #for $archive in $archive_data
        <td class="data new_row hilo_$archive[0]">
          #set $xv = $getattr($archive[1], $x[0])
          <span class="timestamp">$xv.maxtime</span>
          <span>$xv.max.format(add_label=False)</span>
        </td>
        #end for
      #elif 'leak_' in $x[0]
        #for $archive in $archive_data
        <td class="data new_row hilo_$archive[0]">
          #set $xv = $getattr($archive[1], $x[0])
          <span class="timestamp">$xv.maxtime</span>
            <span>$xv.max.format("%.2f", add_label=False)</span><br/>
          <span class="timestamp">$xv.mintime</span>
            <span>$xv.min.format("%.2f", add_label=False)</span>
        </td>
        #end for
      #else
        #for $archive in $archive_data
        <td class="data new_row hilo_$archive[0]">
          #set $xv = $getattr($archive[1], $x[0])
          <span class="timestamp">$xv.maxtime</span>
            <span>$xv.max.format(add_label=False)</span><br/>
          <span class="timestamp">$xv.mintime</span>
            <span>$xv.min.format(add_label=False)</span>
        </td>
        #end for
      #end if
      #if ('soilMoist' in $x[0] or 'leafWet' in $x[0] ) and $ecowitt == 1
        <td class="units">%</td>
      #else
        <td class="units">$getattr($unit.label, $x[0], '')</td>
      #end if  
      </tr>
    #end if
  #end if
#end for

    </tbody>
  </table>
  </div>
</div>
