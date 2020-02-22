
import urllib.request, urllib.error, urllib.parse

url = 'https://www.sap.com/belgique/index.html'
response = urllib.request.urlopen(url)
webContent = response.read()

f = open('odoo.html', 'wb') # perhaps wb
f.write(webContent.decode().replace("SAP", "Odoo").encode())
f.close()