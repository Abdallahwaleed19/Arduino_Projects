from flask import Flask, request, jsonify, render_template_string
import paho.mqtt.client as mqtt

app = Flask(__name__)

MQTT_BROKER = "d926ca8ce9ed4dd7980ecb3cded1608b.s1.eu.hivemq.cloud"
MQTT_PORT = 8883
MQTT_USER = "Wireless_Car"
MQTT_PASS = "Abdallah2112004"
TOPIC = "car/abdallah/car-esp1/cmd"

mqttc = mqtt.Client()
mqttc.tls_set()
mqttc.username_pw_set(MQTT_USER, MQTT_PASS)
mqttc.connect(MQTT_BROKER, MQTT_PORT)
mqttc.loop_start()

@app.route("/")
def index():
    return render_template_string(HTML)

@app.route("/cmd", methods=["POST"])
def cmd():
    c = request.json.get("cmd")
    mqttc.publish(TOPIC, c)
    print("SEND:", c)
    return jsonify(ok=True)

HTML = """
<!DOCTYPE html>
<html>
<body style="background:#111;color:white;text-align:center">

<h2>🔥 Fire Fighting Car 🔥</h2>

<button onclick="send('F')">⬆</button><br>
<button onclick="send('L')">⬅</button>
<button onclick="send('S')">STOP</button>
<button onclick="send('R')">➡</button><br>
<button onclick="send('B')">⬇</button><br><br>

<button onclick="send('C')">SCAN ON</button>
<button onclick="send('X')">SCAN OFF</button>

<script>
function send(c){
 fetch('/cmd',{
  method:'POST',
  headers:{'Content-Type':'application/json'},
  body:JSON.stringify({cmd:c})
 })
}
</script>
</body>
</html>
"""

app.run("0.0.0.0",5000)
