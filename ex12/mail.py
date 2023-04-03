import smtplib
from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText
from email.mime.base import MIMEBase
from email import encoders

# E-posta gönderim bilgileri
FROM = 'e.cayir2022@gtu.edu.tr'
TO = 'bhdrblt5@outlook.com'
SUBJECT = 'Hey hey hey!'
BODY = 'Bu bir deneme mailidir.'
FILE_PATH = '/Users/bbolat/Downloads/logo.png'  # file path

# SMTP logging
smtp = smtplib.SMTP("smtp.office365.com", 587) # safe port
smtp.ehlo()
smtp.starttls()
smtp.login('e.cayir2022@gtu.edu.tr', 'boston1907..')

# Email attachment and body
msg = MIMEMultipart()
msg['From'] = FROM
msg['To'] = TO
msg['Subject'] = SUBJECT

msg.attach(MIMEText(BODY, 'plain'))

with open(FILE_PATH, "rb") as attachment: # rb - read binary
    base = MIMEBase("application", "octet-stream") # crate a object from MIMEBase class. Object represents attachment file.
    base.set_payload(attachment.read()) # use payload for payloading attachment to MIME
    encoders.encode_base64(base) # encoding attachment with base64
    base.add_header("Content-Disposition", f"attachment; filename={FILE_PATH.split('/')[-1]}")
    msg.attach(base) #msg + MIME

# sending email
smtp.sendmail(FROM, TO, msg.as_string())
print("Done! Check the mailbox.")
smtp.quit()
