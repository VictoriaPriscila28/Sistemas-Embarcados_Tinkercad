import tkinter as tk
#import RPi.GPIO as GPIO

RPWM= 11
LPWM = 12
ENR = 15
ENL = 16

def startPWM():
    #r_pwm.start(0)
    #l_pwm.start(0)
    freq.set("2000")
    DC.set("0")


def stopPWM():
    #r_pwm.stop()
    #l_pwm.stop()
    freq.set("")
    DC.set("")

def closeProgram():
    #GPIO.cleanup()
    janela.destroy()

def update(i):
    #l_pwm.ChangeDutyCycle(i)
    #r_pwm.ChangeDutyCycle(0)
    DC.set(i)
    if float(i) < 0:
        LPWM = 1
        RPWM = 0
    elif float(i) > 0:
        LPWM = 0
        RPWM = 1
    else:
        (i)=0

#GPIO.setmode(GPIO.BOARD)
#GPIO.setup(RPWM, GPIO.OUT)
#GPIO.setup(LPWM, GPIO.OUT)
#GPIO.setup(ENR, GPIO.OUT)
#GPIO.setup(ENL, GPIO.OUT)
#GPIO.output(ENR, 1)
#GPIO.output(ENL, 1)
#r_pwm = GPIO.PWM(RPWM,1000)
#l_pwm = GPIO.PWM(LPWM,1000)

janela = tk.Tk()
janela.title("PWM Configurator")



buttonON = tk.Button(janela, text="Start PWM", font=("Arial",24,"bold"), command=startPWM)
buttonOFF = tk.Button(janela, text='Stop PWM', font=("Arial",24,"bold"), command=stopPWM)
buttonClose = tk.Button(janela, text="Fechar", font=("Arial",24,"bold"), command=closeProgram)

buttonON.grid(column=4, row=1, padx=10, pady=10)
buttonOFF.grid(column=4, row=2, padx=10, pady=10)
buttonClose.grid(column=4, row=3, padx=10, pady=10)

freq=tk.StringVar()
DC=tk.StringVar()

labelFREQ = tk.Label(janela, text="Frequência(Hz): ", font=("Arial",24,"bold"))
labelDC = tk.Label(janela, text="Duty Cycle(%): ", font=("Arial",24,"bold"))
labelCDC = tk.Label(janela, text="Change Duty Clyce (%): ", font=("Arial",24,"bold"))

labelFREQ.grid(column=1, row=1, padx=10, pady=10)
labelDC.grid(column=1, row=2, padx=10, pady=10)
labelCDC.grid(column=1, row=3, padx=10, pady=10)

labelSHOW_freq = tk.Label(janela, textvariable=freq, bg="white", font=("Arial",24,"bold"), height=2, width=20)
labelSHOW_dc = tk.Label(janela, textvariable=DC, bg="white", font=("Arial",24,"bold"), height=2, width=20)


labelSHOW_freq.grid(column=2, row=1, padx=10, pady=10)
labelSHOW_dc.grid(column=2, row=2, padx=10, pady=10)

slider = tk.Scale(janela, from_=2000, to=0, length=300, width=35, orient=tk.HORIZONTAL, command=update, showvalue=10)
slider.grid(column=1, row=4, padx=10, pady=10, rowspan=3, sticky=tk.SW)
slider.set(100)


janela.mainloop()
