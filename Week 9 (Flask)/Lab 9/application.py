import os

from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///birthdays.db")

MONTHS = {"January": "1", "Febuary": "2", "March": "3", "April": "4", "May": "5", "June": "6", "July": "7", "August": "8", "September": "9", "October": "10", "November": "11", "December": "12"}
DAYS = []
for i in range(1, 32, 1):
    DAYS.append(i)

@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":
        name = request.form.get("name")
        monthName = request.form.get("month")
        monthNum = MONTHS[month1]
        day = request.form.get("day")

        # db.execute("INSERT INTO birthdays (name, month, day) VALUES (?, ?, ?)", name, monthName, day)
        db.execute("INSERT INTO birthdays (name, month, day) VALUES (?, ?, ?)", name, monthNum, day)
        return redirect("/")

    else:
        birthdays = db.execute("SELECT * FROM birthdays")
        return render_template("index.html", birthdays=birthdays, months=MONTHS, days=DAYS)


