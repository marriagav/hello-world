import random
import smtplib
from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText
from string import Template

class Persona:

    def __init__(self,name,email):
        self.name = name
        self.email = email
        self.taken = False
        self.lista=[]
    
    def setSecretSanta(self,persona):
        self.secretSanta = persona
    
    def setLista(self,lista):
        self.lista = lista
    
    def take(self):
        self.taken = True
    
    def addToList(self,item):
        self.lista.append(item)

class Programa:

    _MY_ADDRESS= "" #HERE GOES THE ADRESS FROM WHICH THE EMAILS ARE SENDED
    _PASSWORD= "" #HERE GOES THE PASSWORD OF THE EMAIL ACCOUNT

    message =Template("""Dear ${PERSON_NAME}, 
The person that you need to gift is ${SECRETSANTA_NAME},
The price range is ${PRECIOS},

Have a great day :)""")

    def __init__(self):
        self.noPersonas = 0
        self.integrantes = []
    
    def addPersona(self,persona):
        self.integrantes.append(persona)
        self.noPersonas+=1
    
    def sortPersonas(self):
        random.shuffle(self.integrantes)
        for x in range(self.noPersonas):
            if x==self.noPersonas-1:
                self.integrantes[x].setSecretSanta(self.integrantes[0])
            else:
                self.integrantes[x].setSecretSanta(self.integrantes[x+1])
        self.integrantes[x].take()
    
    def setPrecios(self, starting_prize, ending_prize):
        self.starting_prize = starting_prize
        self.ending_prize = ending_prize
    
    def setSubject(self,subject):
        self.subject = subject

    def initializeMail(self):
        # set up the SMTP server
        self.adress = self._MY_ADDRESS

        #self.s = smtplib.SMTP(host='smtp-mail.outlook.com', port=587) #-- Hotmail
        self.s = smtplib.SMTP(host='smtp.gmail.com', port=587) #-- Gmail
        self.s.starttls()
        self.s.login(self.adress, self._PASSWORD)
    
    def sendMails(self):
        self.initializeMail()
        for x in self.integrantes:
            msg = MIMEMultipart()       # create a message
            priceStr="$"+str(self.starting_prize)+" a $" + str(self.ending_prize)
            message = self.message.substitute(PERSON_NAME=x.name,SECRETSANTA_NAME=x.secretSanta.name, PRECIOS=priceStr)
            #message=message.substitute(SECRETSANTA_NAME=x.secretSanta.name)
            # setup the parameters of the message
            msg['From']=self.adress
            msg['To']=x.email
            if "intercambio" in self.subject.lower():
                msg['Subject']=self.subject
            else:
                msg['Subject']="Intercambio " + self.subject
            # add in the message body
            msg.attach(MIMEText(message, 'plain'))
            # send the message via the server set up earlier.
            self.s.send_message(msg)
            del msg
    
    def clear(self):
        for x in range(self.noPersonas):
            self.integrantes.pop(0)
        self.noPersonas=0