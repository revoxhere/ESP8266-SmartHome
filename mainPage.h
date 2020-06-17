const char MAIN_page[] PROGMEM = R"=====(
	<!DOCTYPE html>
		<head>
	 		<title>Smart Sockets v2 by revox</title>
	 		<style>
	 			h1, table {
	 				font-family: Arial, Helvetica, sans-serif;
	 			}
	 			table {
	 				font-size: 20;
	 			}
	 			.button1 {
					border: none;
					color: #2ecc71;
				 	padding: 15px 32px;
				  	text-align: center;
				  	font-weight: bold;
				  	text-decoration: none;
				  	display: inline-block;
				  	font-size: 12px;
				  	margin: 4px 2px;
				  	cursor: pointer;
				  	background-color: #2c3e50;
				}
				.button2 { 
				  	border: none;
				  	font-style: bold;
				  	font-weight: bold;
				  	color: #e74c3c;
				  	padding: 15px 32px;
				  	text-align: center;
				  	text-decoration: none;
				  	display: inline-block;
				  	font-size: 12px;
				  	margin: 4px 2px;
				  	cursor: pointer;
				  	background-color: #2c3e50;
				}
	 		</style>
		</head>
	<body>
		<center>
			<form action="/form" method="post">
			<h1 style="text-align: center;"><span style="color: #3498db;"><strong>Smart Sockets v2 by revox</strong></span></h1>
			<br /><table>
				<tbody>
					<tr>
						<td>Untitled <span style="color: #999999;">1</span>&nbsp;<input class="button1" name="submit" type="SUBMIT" value="ON1" /> <input class="button2" name="submit" type="SUBMIT" value="OFF1" /></td>
						<td>@@L1@@</td>
					</tr>
					<tr>
						<td>Untitled <span style="color: #999999;">2</span>&nbsp;<input class="button1" name="submit" type="SUBMIT" value="ON2" /> <input class="button2" name="submit" type="SUBMIT" value="OFF2" /></td>
						<td>@@L2@@</td>
					</tr>
					<tr>
						<td>Untitled <span style="color: #999999;">3</span>&nbsp;<input class="button1" name="submit" type="SUBMIT" value="ON3" /> <input class="button2" name="submit" type="SUBMIT" value="OFF3" /></td>
						<td>@@L3@@</td>
					</tr>
					<tr>
						<td>Untitled <span style="color: #999999;">4</span>&nbsp;<input class="button1" name="submit" type="SUBMIT" value="ON4" /> <input class="button2" name="submit" type="SUBMIT" value="OFF4" /></td>
						<td>@@L4@@</td>
					</tr>
					<tr>
						<td>Untitled <span style="color: #999999;">5</span>&nbsp;<input class="button1" name="submit" type="SUBMIT" value="ON5" /> <input class="button2" name="submit" type="SUBMIT" value="OFF5" /></td>
						<td>@@L5@@</td>
					</tr>
					<tr>
						<td>Untitled <span style="color: #999999;">5</span>&nbsp;<input class="button1" name="submit" type="SUBMIT" value="ON5" /> <input class="button2" name="submit" type="SUBMIT" value="OFF5" /></td>
						<td>@@L6@@</td>
					</tr>
				</tbody>
			</table>
			</form>
		</center>
	</body>
)=====";
