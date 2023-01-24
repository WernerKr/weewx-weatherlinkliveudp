## identifier for weewx skins
## Copyright Tom Keffer, Matthew Wall
## See LICENSE.txt for your rights
#errorCatcher Echo
#encoding UTF-8

#set $allways_lang = False
#set $use_lang = False
#if '4.6' in $station.version or $allways_lang == True
  #set $use_lang = True
#end if

#if $use_lang
<div id='identifier_widget' class="widget">
  <div class="widget_title">
  </div>
  <div class="widget_contents">
  <table>
    <tr>
      <td class="label">$gettext("Latitude")</td>
      <td class="data">$station.latitude[0]&deg; $station.latitude[1]' $station.latitude[2]</td>
    </tr>
    <tr>
      <td class="label">$gettext("Longitude")</td>
      <td class="data">$station.longitude[0]&deg; $station.longitude[1]' $station.longitude[2]</td>
    </tr>
    <tr>
      <td class="label">$pgettext("Geographical", "Altitude")</td>
      <td class="data">$station.altitude</td>
    </tr>
    <tr>
      <td class="label">WeeWX</td>
      <td class="data">$station.version</td>
    </tr>
  </table>
  </div>

</div>

#else
<div id='identifier_widget' class="widget">
  <div class="widget_title">
  </div>
  <div class="widget_contents">
  <table>
    <tr>
      <td class="label">Latitude</td>
      <td class="data">$station.latitude[0]&deg; $station.latitude[1]' $station.latitude[2]</td>
    </tr>
    <tr>
      <td class="label">Longitude</td>
      <td class="data">$station.longitude[0]&deg; $station.longitude[1]' $station.longitude[2]</td>
    </tr>
    <tr>
      <td class="label">Altitude</td>
      <td class="data">$station.altitude</td>
    </tr>
    <tr>
      <td class="label">WeeWX</td>
      <td class="data">$station.version</td>
    </tr>
  </table>
  </div>

</div>
#end if