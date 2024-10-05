# -*- coding: utf-8 -*-
import time
from calendar import isleap

# Returns True if the year is a leap year
def judge_leap_year(year):
    return isleap(year)

# Returns the number of days in each month
def month_days(month, leap_year):
    days_in_month = [31, 28 + leap_year, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    return days_in_month[month - 1]  # month is 1-indexed

# Get user input
name = input("Input your name: ")
while True:
    try:
        age = int(input("Input your age: "))
        if age < 0:
            raise ValueError("Age cannot be negative.")
        break
    except ValueError as e:
        print(f"Invalid input: {e}. Please enter a valid age.")

localtime = time.localtime(time.time())

# Calculate total months and days
year = age
month = year * 12 + localtime.tm_mon
day = 0

# Calculate the total days from the years
begin_year = localtime.tm_year - year
for y in range(begin_year, begin_year + year):
    day += 366 if judge_leap_year(y) else 365

# Calculate the days for the current month
leap_year = judge_leap_year(localtime.tm_year)
for m in range(1, localtime.tm_mon):
    day += month_days(m, leap_year)

# Add the days of the current month
day += localtime.tm_mday

# Output results
print(f"{name}'s age is {year} years or {month} months or {day} days.")
