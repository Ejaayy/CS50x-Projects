from flask import Flask, render_template, request

app = Flask(__name__) #special variabel that refers to current file __name__

@app.route("/", methods=["GET","POST"])
def index():
    if request.method=="POST":
        name = request.form.get("name","world")
        return render_template("greet.html", name=name)
    else:
        return render_template("index.html")
