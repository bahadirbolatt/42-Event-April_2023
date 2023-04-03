import smtplib

server = smtplib.SMTP('smtp.office365.com', 587) # 587 is a safe port.

server.ehlo()
server.starttls()
server.login('e.cayir2022@gtu.edu.tr', 'boston1907...')

try:
    print("logging accept...")
except:
    print("login failed")
    exit()

subject = "Test"
body = "This is a test."
message = f"Subject: {subject}\n\n{body}"
server.sendmail('e.cayir2022@gtu.edu.tr', 'bhdrblt5@outlook.com', message)
server.quit()
