## about module for weewx skins
## Copyright Tom Keffer, Matthew Wall
## See LICENSE.txt for your rights
#errorCatcher Echo
#encoding UTF-8

<div id='about_widget' class="widget">
  <div class="widget_title">
    #if '4.6' in $station.version
     $gettext("About this station")
    #else
     About this weather station
    #end if
    <a class="widget_control"
    onclick="toggle_widget('about')">&diams;</a>
  </div>
  <div class="widget_contents">
  <table>
    <tr>
    #if '4.6' in $station.version
      <td class="label">$gettext("Hardware")</td>
    #else
      <td class="label">Hardware</td>
    #end if
      <td class="data">$station.hardware</td>
    </tr>
    <tr>
    #if '4.6' in $station.version
      <td class="label">$gettext("Latitude")</td>
    #else
      <td class="label">Latitude</td>
    #end if
      <td class="data">$station.latitude[0]&deg; $station.latitude[1]' $station.latitude[2]</td>
    </tr>
    <tr>
    #if '4.6' in $station.version
      <td class="label">$gettext("Longitude")</td>
    #else
      <td class="label">Longitude</td>
    #end if
      <td class="data">$station.longitude[0]&deg; $station.longitude[1]' $station.longitude[2]</td>
    </tr>
    <tr>
    #if '4.6' in $station.version
      <td class="label">$pgettext("Geographical", "Altitude")</td>
    #else
      <td class="label">Altitude</td>
    #end if
      <td class="data">$station.altitude</td>
    </tr>
    <tr>
    #if '4.6' in $station.version
      <td class="label">$gettext("Server uptime")</td>
    #else
      <td class="label">Server uptime</td>
    #end if
      <td class="data">$station.os_uptime</td>
    </tr>
    <tr>
    #if '4.6' in $station.version
      <td class="label">$gettext("WeeWX uptime")</td>
    #else
      <td class="label">WeeWX uptime</td>
    #end if
      <td class="data">$station.uptime</td>
    </tr>
    <tr>
    #if '4.6' in $station.version
      <td class="label">$gettext("WeeWX version")</td>
    #else
      <td class="label">WeeWX version</td>
    #end if
      <td class="data">$station.version</td>
    </tr>
    #if '4.6' in $station.version
    <tr>
      <td class="label">$gettext("Skin")</td>
      <td class="data">$SKIN_NAME $SKIN_VERSION</td>
    </tr>
    #end if
  </table>
  </div>

</div>
