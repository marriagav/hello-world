from backend import Programa, Persona
import tkinter as tk
from tkinter import ttk
from tkinter import messagebox
from tkinter import END
from ttkthemes import ThemedStyle

LARGE_FONT=('Verdana', 12, 'bold')
SMALL_FONT=("Verdana",8)

#COLOR_FONDO="floral white"
#COLOR_FONDO="antique white"
COLOR_FONDO="light steel blue"

test=Programa()

class Application(tk.Tk):

    def __init__(self, *args,**kwargs):
        tk.Tk.__init__(self, *args,**kwargs)

        #StartPage.configure(self,bg="red")
        #tk.Tk.ThemedTk(theme="arc")
        tk.Tk.iconbitmap(self,default="santa_hat.ico")
        tk.Tk.wm_title(self,"Secret Santa")

        self.resizable(False, False)
        self.update_idletasks()

        
        self.style = ttk.Style(self)
        #self.style.configure(self,bg="red")
        self.style.theme_use("vista")

        #style=ThemedStyle(self)
        #style.set_theme("adapta")

        container=ttk.Frame(self)
        container.pack(side="top", fill="both",expand=True)
        container.grid_rowconfigure(0,weight=1)
        container.grid_columnconfigure(0,weight=1)

        self.frames={}

        for F in (StartPage,PageOne,addPage,pricePage,editPage):

            frame=F(container, self)

            self.frames[F]= frame

            frame.grid(row=0, column=0, sticky="nsew")


        self.show_frame(StartPage)


    def show_frame(self,cont):
        frame=self.frames[cont]
        frame.tkraise()
    
    def get_page(self, page_class):
        return self.frames[page_class]

class StartPage(tk.Frame):

    def __init__(self,parent,controller):
        tk.Frame.__init__(self,parent)
        label=ttk.Label(self,text="Start",font=LARGE_FONT)
        label.configure(background=COLOR_FONDO)
        label.grid(row=0, columnspan=3)
        label.pack(pady=10,padx=10)

        self.configure(bg=COLOR_FONDO)

        button1=ttk.Button(self,text="Start program",
         command=lambda: controller.show_frame(pricePage))
        
        #button1.configure(color="peach puff")
        
        button1.pack()

class PageOne(tk.Frame):
    
    def __init__(self,parent, controller):

        tk.Frame.__init__(self,parent)
        label=ttk.Label(self,text="Participants",font=LARGE_FONT)
        label.configure(background=COLOR_FONDO)
        label.grid(row=0, columnspan=3)

        self.configure(bg=COLOR_FONDO)

        # create Treeview with 3 columns
        cols = ('Number', 'Name', 'Email')
        self.listBox = ttk.Treeview(self, columns=cols, show='headings')
        # set column headings
        for col in cols:
            self.listBox.heading(col, text=col)    
        
        #self.listBox.configure(background=COLOR_FONDO)
        self.listBox.grid(row=1, column=0, columnspan=2)

        #self.listBox.after(1000, self.show)

        button1=ttk.Button(self,text="Return",
         command=lambda: controller.show_frame(pricePage)).place(x = 0, y = 249)
        
        button2=ttk.Button(self,text="Add",
         command=lambda: controller.show_frame(addPage)).place(x = 320, y = 249)
        
        button5=ttk.Button(self,text="Edit",
         command=lambda: self.edit(controller)).grid(row=4, column=1)
        
        button3=ttk.Button(self,text="Restart",
         command=self.clean).place(x = 470, y = 249)

        button4=ttk.Button(self,text="Finalize",
         command=lambda: self.end(controller),width=8).place(x = 545, y = 249)
    
    def edit(self,controller):
        try:
            name=self.listBox.item(self.listBox.selection())['values'][0]
            #print(name)
            page = controller.get_page(editPage)
            page.setRegister(name)
            page.fill()
            controller.show_frame(editPage)
        except:
            messagebox.showinfo(title="Error",message="Select a record")

    
    def show(self):
        self.listBox.delete(*self.listBox.get_children())
        tempList = test.integrantes
        cont=1

        for i in range(len(tempList)):
            self.listBox.insert("", "end", values=(cont, tempList[i].name, tempList[i].email))
            cont+=1

        #self.listBox.after(1000, self.show)
    
    def clean(self,ending=False):
        if ending:
            self.listBox.delete(*self.listBox.get_children())
            try:
                test.clear()
            except:
                pass
            #self.listBox.after(1000, self.show)
        else:
            messageDelete = messagebox.askyesno("Confirmation", "Do you want to start again?")
            if messageDelete > 0:
                self.listBox.delete(*self.listBox.get_children())
                try:
                    test.clear()
                except:
                    pass
                #self.listBox.after(1000, self.show)
    
    def end(self,controller):
        messageDelete = messagebox.askyesno("Confirmation", "Do you want to continue?")
        if messageDelete > 0:
            if test.noPersonas<1:
                messagebox.showinfo(title="Error",message="List empty")
                return
            test.sortPersonas()
            try:
                test.sendMails()
                messagebox.showinfo(title="Sucess",message="Emails sent!")
                self.clean(ending=True)
                controller.show_frame(StartPage)
            except:
                messagebox.showinfo(title="Error",message="Invalid email address")
                self.clean()

class addPage(tk.Frame):

    def __init__(self,parent,controller):

        tk.Frame.__init__(self,parent)
        label=ttk.Label(self,text="Add",font=LARGE_FONT)
        label.configure(background=COLOR_FONDO)
        label.pack(pady=10,padx=10)

        self.configure(bg=COLOR_FONDO)

        nombre = ttk.Label(self,text="Name",font=SMALL_FONT)
        nombre.configure(background=COLOR_FONDO)
        nombre.place( x = 150, y = 100)
        self.textBox_nombre = ttk.Entry(self,width=30)
        self.textBox_nombre.place(x = 217, y = 100)
        mail = ttk.Label(self,text="E-Mail",font=SMALL_FONT)
        mail.configure(background=COLOR_FONDO)
        mail.place( x = 150, y = 130)
        self.textBox_email = ttk.Entry(self,width=30)
        self.textBox_email.place(x = 217, y = 130)

        button2=ttk.Button(self,text="Return",
         command=lambda: self.show_and_clear(controller)).place(x = 0, y = 249)

        button1=ttk.Button(self,text="Add",
         command=self.add).place(x = 525, y = 249)
    
    def show_and_clear(self,controller):
        page = controller.get_page(PageOne)
        page.show()
        controller.show_frame(PageOne)

    def add(self):
        if self.textBox_nombre.index("end") == 0 or self.textBox_email.index("end")==0:
            messagebox.showinfo(title="Error",message="Empty field")
            return
        test.addPersona(Persona(self.textBox_nombre.get(),self.textBox_email.get()))
        messagebox.showinfo(title="Sucess",message="Record added")
        self.textBox_nombre.delete(0, END)
        self.textBox_email.delete(0, END)

class editPage(tk.Frame):

    def __init__(self,parent,controller):

        tk.Frame.__init__(self,parent)
        label=ttk.Label(self,text="Edit",font=LARGE_FONT)
        label.configure(background=COLOR_FONDO)
        label.pack(pady=10,padx=10)

        self.configure(bg=COLOR_FONDO)

        nombre = ttk.Label(self,text="Name",font=SMALL_FONT)
        nombre.configure(background=COLOR_FONDO)
        nombre.place( x = 150, y = 100)
        self.textBox_nombre = ttk.Entry(self,width=30)
        self.textBox_nombre.place(x = 217, y = 100)
        mail = ttk.Label(self,text="E-Mail",font=SMALL_FONT)
        mail.configure(background=COLOR_FONDO)
        mail.place( x = 150, y = 130)
        self.textBox_email = ttk.Entry(self,width=30)
        self.textBox_email.place(x = 217, y = 130)

        button2=ttk.Button(self,text="Return",
         command=lambda: self.show_and_clear(controller)).place(x = 0, y = 249)

        button1=ttk.Button(self,text="Confirm",
         command=lambda: self.edit(controller)).place(x = 525, y = 249)
        
        button3=ttk.Button(self,text="Delete",
         command=lambda: self.delete(controller)).place(x = 450, y = 249)
    
    def setRegister(self,name):
        self.reg=name
    
    def fill(self):
        self.textBox_nombre.delete(0, END)
        self.textBox_email.delete(0, END)
        self.textBox_nombre.insert(0,test.integrantes[self.reg-1].name)
        self.textBox_email.insert(0,test.integrantes[self.reg-1].email)
    
    def show_and_clear(self,controller):
        page = controller.get_page(PageOne)
        page.show()
        controller.show_frame(PageOne)

    def edit(self,controller):
        if self.textBox_nombre.index("end") == 0 or self.textBox_email.index("end")==0:
            messagebox.showinfo(title="Error",message="Empty field")
            return
        test.integrantes[self.reg-1].email = self.textBox_email.get()
        test.integrantes[self.reg-1].name = self.textBox_nombre.get()
        messagebox.showinfo(title="Sucess",message="Record edited")
        self.textBox_nombre.delete(0, END)
        self.textBox_email.delete(0, END)
        self.show_and_clear(controller)
    
    def delete(self,controller):
        messageDelete = messagebox.askyesno("Confirmation", "Do you want to delete this record?")
        if messageDelete > 0:
            test.integrantes.pop(self.reg-1)
            test.noPersonas-=1
            messagebox.showinfo(title="Sucess",message="Record deleted")
            self.textBox_nombre.delete(0, END)
            self.textBox_email.delete(0, END)
            self.show_and_clear(controller)


class pricePage(tk.Frame):

    def __init__(self,parent,controller):

        tk.Frame.__init__(self,parent)
        label=ttk.Label(self,text="Secret Santa information",font=LARGE_FONT)
        label.configure(background=COLOR_FONDO)
        label.pack(pady=10,padx=10)

        self.configure(bg=COLOR_FONDO)

        nombreI = ttk.Label(self,text="Name of the Secret Santa",font=SMALL_FONT)
        nombreI.configure(background=COLOR_FONDO)
        nombreI.place( x = 225, y = 70)
        self.textBox_nombreI = ttk.Entry(self,width=30)
        self.textBox_nombreI.place(x = 207, y = 90)

        label=ttk.Label(self,text="Price Range",font=SMALL_FONT)
        label.configure(background=COLOR_FONDO)
        label.place( x = 250, y =130)

        precioI = ttk.Label(self,text="From:",font=SMALL_FONT)
        precioI.configure(background=COLOR_FONDO)
        precioI.place( x = 165, y = 150)
        self.textBox_precioI = ttk.Entry(self,width=30)
        self.textBox_precioI.place(x = 207, y = 150)

        precioF = ttk.Label(self,text="To:",font=SMALL_FONT)
        precioF.configure(background=COLOR_FONDO)
        precioF.place( x = 180, y = 170)
        self.textBox_precioF = ttk.Entry(self,width=30)
        self.textBox_precioF.place(x = 207, y = 170)

        button2=ttk.Button(self,text="Return",
         command=lambda: controller.show_frame(StartPage)).place(x = 0, y = 249)

        button1=ttk.Button(self,text="Continue",
         command=lambda: self.addPrice(controller)).place(x = 525, y = 249)
    
    def addPrice(self,controller):
        if self.textBox_precioI.index("end") == 0 or self.textBox_precioF.index("end")==0 or self.textBox_nombreI.index("end")==0:
            messagebox.showinfo(title="Error",message="Empty field")
            return
        
        test.setSubject(self.textBox_nombreI.get())
        test.setPrecios(self.textBox_precioI.get(),self.textBox_precioF.get())
        #messagebox.showinfo(title="Éxito",message="¡Agregado con éxito!")
        self.textBox_precioI.delete(0, END)
        self.textBox_precioF.delete(0, END)
        self.textBox_nombreI.delete(0, END)
        controller.show_frame(PageOne)

def main():
    app = Application()
    app.mainloop()

main()