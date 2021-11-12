from flask import Flask,redirect,render_template,request,url_for,session
import time	
import re

app = Flask(__name__)
app.secret_key = "secret"

@app.route("/", methods = ['GET','POST'])
def index():
	try:
		count = session["count"]
		balance = session["balance"]
	except KeyError:
		count = session["count"] =0
		balance = session["count"] = 10000

	if request.method == "GET":
		return render_template("test.html",balance = balance , msg = "TEST")

	if request.method == "POST":
		if  int(request.form["amount"]) >= balance :
			msg = "Not enough money"
			return render_template("test.html", balance=balance, msg=msg)
		else:
			msg = "withdrawn"
			return render_template("test.html",balance = (balance-int(request.form["amount"])), msg = msg)
if __name__ == "__main__":
	app.run()