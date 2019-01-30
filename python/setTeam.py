from selenium import webdriver
import time

driver = webdriver.Firefox()
driver.get('http://games.espn.com/fba/clubhouse?leagueId=52837&teamId=7&seasonId=2018')
time.sleep(3)

def getPlayerIds():
    findPlayers = driver.find_elements_by_css_selector('tr[id*=plyr]')
    idList = []
    for i in findPlayers:
        idList.append(i.get_attribute('id'))
    for i in range(len(idList)):
        idList[i] = idList[i][4:]
    return idList

def logUserIn(email, password):
    logIn = driver.find_element_by_css_selector('.user > a:nth-child(1)')
    logIn.click()    
    time.sleep(3)
    iframe = driver.find_element_by_css_selector('iframe[id=disneyid-iframe]')
    driver.switch_to_frame(iframe)
    userNameEntry = driver.find_element_by_css_selector('input[type=email]')
    userNameEntry.send_keys(email)
    passwordEntry = driver.find_element_by_css_selector('input[type=password]')
    passwordEntry.send_keys(password)
    passwordEntry.submit()
    submitButton = driver.find_element_by_css_selector('button.btn:nth-child(2)')
    submitButton.click()
    driver.switch_to_default_content()
    time.sleep(7)
    return 1

def checkWhoPlays():
    times = driver.find_elements_by_class_name('gameStatusDiv')
    inactives = []
    x=0
    for i in times:
        if i.text == '':
            inactives.append(x)
        x += 1
    return inactives

def getPlayerNames(list1, list2):
    number = 0
    players = []
    for i in list2:
        if number in list1:
            players.append(driver.find_element_by_id('playername_' + str(i)))
        number += 1
    names = []
    for i in players:
        names.append(i.text)
    return names

def makeDecision(list1, list2):
    if len(list1) == 0:
        return "No changes made"
    changes = 0
    for i in range(10):
        if i in list1:
            foundSwitch = False
            move = driver.find_element_by_id('pncButtonMove_' + str(list2[i]))
            move.click()
            for j in range(10,13):
                if j in list1:
                    continue
                try:
                    moveTo = driver.find_element_by_id('pncButtonHere_' + str(j))
                except:
                    continue
                if moveTo.is_displayed():
                    foundSwitch = True
                    changes += 1
                    moveTo.click()
                    submit = driver.find_element_by_id('pncSaveRoster1')
                    submit.click()
                    list1.append(j)
                    break
            if foundSwitch == False:
                #print('Nothing Found')
                moveBack = driver.find_element_by_id('pncButtonMoveSelected_' + str(list2[i]))
                moveBack.click()
    return str(changes) + " changes made"
        
playerIds = getPlayerIds()
#print(playerIds)
logUserIn('512seanjones@gmail.com', 'sjones1616')        
inactiveSlots = checkWhoPlays()
#print(inactiveSlots)
inactiveNames = getPlayerNames(inactiveSlots, playerIds)
#print('Inactive Players: ' + str(inactiveNames))
result = makeDecision(inactiveSlots,playerIds)
#print(result)
driver.quit()
