import time
import network
import requests
import re
import sys
from radiodeets import URL, PIN, TIMEOUT

print(sys.argv)



# req = requests.get(URL + "fsapi/CREATE_SESSION?pin=" + PIN)
# print(str(req.content))

# SESSION = re.findall("\d+", str(req.content))[0]


# res = requests.get(URL + "fsapi/SET/netRemote.sys.audio.volume?pin=" + PIN + "&sid=" + SESSION + "&value=12")
# res = requests.get(URL + "fsapi/SET/netRemote.sys.mode?pin=" + PIN + "&sid=" + SESSION + "&value=0")
# res = requests.get(URL + "fsapi/SET/netRemote.sys.power?pin=" + PIN + "&sid=" + SESSION + "&value=1")
# res = requests.get(URL + "fsapi/SET/netRemote.nav.state?pin=" + PIN + "&value=1")
# res = requests.get(URL + "fsapi/SET/netRemote.nav.action.selectPreset?pin=" + PIN + "&value=0")
