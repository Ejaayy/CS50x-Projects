from flask import Flask, render_template, request

app = Flask(__name__) #special variabel that refers to current file __name__

SPORTS = ["Basketball", "Football","Soccer", "Ultimate Frisbee"]

@app.route("/")
def index():
    return render_template("index.html", sports = SPORTS) #actual  variable is capslock

@app.route("/register", methods=["POST"])
def register():

    if not request.form.get("name") or request.form.get("sport") not in SPORTS:
        return render_template("failure.html")

    for sport in request.form.getlist("sport"):
        if sport not in SPORTS:
            return render_template("failure.html")
    return render_template("success.html")
