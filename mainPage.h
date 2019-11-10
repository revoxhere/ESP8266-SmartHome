const char MAIN_page[] PROGMEM = R"=====(
<head>
  <title>Smart Home</title>
</head>
<p></p>
<center><form action="/form" method="post">
<p style="text-align: center;"><span style="color: #008080;"><strong>Smart Home by revox</strong></span></p>
<br />
<table>
<tbody>
<tr>
<td>Bez nazwy <span style="color: #999999;">1</span>&nbsp; <input name="submit" type="SUBMIT" value="ON1" /> <input name="submit" type="SUBMIT" value="OFF1" /></td>
<td>@@L1@@</td>
</tr>
<tr>
<td>Bez nazwy <span style="color: #999999;">2</span>&nbsp;&nbsp;<input name="submit" type="SUBMIT" value="ON2" /> <input name="submit" type="SUBMIT" value="OFF2" /></td>
<td>@@L2@@</td>
</tr>
<tr>
<td>Bez nazwy<span style="color: #999999;"> 3</span>&nbsp;&nbsp;<input name="submit" type="SUBMIT" value="ON3" /> <input name="submit" type="SUBMIT" value="OFF3" /></td>
<td>@@L3@@</td>
</tr>
<tr>
<td>Bez nazwy <span style="color: #999999;">4&nbsp;</span>&nbsp;<input name="submit" type="SUBMIT" value="ON4" /> <input name="submit" type="SUBMIT" value="OFF4" /></td>
<td>@@L4@@</td>
</tr>
<tr>
<td>Bez nazwy <span style="color: #999999;">5</span>&nbsp;&nbsp;<input name="submit" type="SUBMIT" value="ON5" /> <input name="submit" type="SUBMIT" value="OFF5" /></td>
<td>@@L5@@</td>
</tr>
<tr>
<td><strong><span style="color: #ff0000;">L</span><span style="color: #008000;">E</span></strong><span style="color: #3366ff;"><strong>D</strong>y</span> <span style="color: #999999;">Tuba&nbsp; &nbsp;</span>&nbsp;<input name="submit" type="SUBMIT" value="ON6" /> <input name="submit" type="SUBMIT" value="OFF6" /></td>
<td>@@L6@@</td>
</tr>
</tbody>
</table>
<p><strong><span style="color: #ff6600;">Temperatura:</span></strong> @@TEMP@@ *C</p>
<p>&nbsp;</p>
<p>&nbsp;</p>
<center><span style="color: #999999;"><a style="color: #999999;" href="http://pom.m-hash.com/index.php?page=login">M-Hash</a></span></center><center><span style="color: #999999;"><a style="color: #999999;" href="http://192.168.0.1">Konfiguracja Routera</a></span></center><center><span style="color: #999999;"><a style="color: #999999;" href="https://www.youtube.com/c/reVox96">Kanal YouTube</a></span></center>
<p>&nbsp;</p>
</form></center>
)=====";
