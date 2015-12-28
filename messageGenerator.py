import collections

letterCounter = collections.Counter()

HOUR = ["TWELVE ","ONE ","TWO ","THREE ","FOUR ","FIVE ","SIX ","SEVEN ","EIGHT ","NINE ","TEN ","ELEVEN ",
        "TWELVE ","ONE ","TWO ","THREE ","FOUR ","FIVE ","SIX ","SEVEN ","EIGHT ","NINE ","TEN ","ELEVEN ","TWELVE "]

MINUTE = {5  : "FIVE MINUTES ",
          10 : "TEN MINUTES ",
          15 : "QUARTER ",
          20 : "TWENTY MINUTES ",
          25 : "TWENTY FIVE MINUTES ",
          30 : "HALF ",
          35 : "TWENTY FIVE MINUTES ",
          40 : "TWENTY MINUTES ",
          45 : "QUARTER ",
          50 : "TEN MINUTES ",
          55 : "FIVE MINUTES "}

for hour in range(0,24):
    for minute in range (0,60,5):
        curLine = "IT IS "
        printhour = hour
        if minute == 0:
            curLine += HOUR[hour] + "OCLOCK "
        else:
            printhour = hour
            curLine += MINUTE[minute]
            if minute > 30:
                printhour = hour+1
                curLine += "TO "
            else:
                curLine += "PAST "
            curLine += HOUR[printhour]
        if hour < 12:
            curLine += "AM"
        else:
            curLine += "PM"
        tempCounter = collections.Counter(curLine.replace(" ",""))
        letterCounter = tempCounter | letterCounter

# Print out minimum letters to make all solutions
letterDict = dict(letterCounter)
for key in letterDict:
    for i in range(letterDict[key]):
        print key
