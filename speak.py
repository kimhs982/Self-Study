import os
import gtts
import requests
import sys
import pygame
import pyaudio
import wave

CHUNK = 1024
FORMAT = pyaudio.paInt16
CHANNELS = 1
RATE = 44100

RECORD_SECONDS = 5
WAVE_OUTPUT_FILENAME = "file.wav"

p = pyaudio.PyAudio()

stream = p.open(format=FORMAT,
                channels=CHANNELS,
                rate=RATE,
                input=True,
                frames_per_buffer=CHUNK)

print('음성녹음을 시작합니다.')

frames = []

for i in range(0, int(RATE/CHUNK*RECORD_SECONDS)):
    data = stream.read(CHUNK)
    frames.append(data)

print('음성녹음을 완료하였습니다.')

stream.stop_stream()
stream.close()
p.terminate()

wf = wave.open(WAVE_OUTPUT_FILENAME, 'wb')
wf.setnchannels(CHANNELS)
wf.setsampwidth(p.get_sample_size(FORMAT))
wf.setframerate(RATE)
wf.writeframes(b''.join(frames))
wf.close()


# init
pygame.mixer.init()

# load file
pygame.mixer.music.load(WAVE_OUTPUT_FILENAME)

# play
# pygame.mixer.music.play()

# 끝까지 재생할때까지 기다린다.
while pygame.mixer.music.get_busy() == True:
    continue


client_id = ""
client_secret = ""

lang = "Kor"  # 언어 코드 ( Kor, Jpn, Eng, Chn )
url = "https://naveropenapi.apigw.ntruss.com/recog/v1/stt?lang=" + lang

data = open(WAVE_OUTPUT_FILENAME, 'rb')

headers = {
    "X-NCP-APIGW-API-KEY-ID": client_id,
    "X-NCP-APIGW-API-KEY": client_secret,
    "Content-Type": "application/octet-stream"
}

response = requests.post(url,  data=data, headers=headers)
rescode = response.status_code

if (rescode == 200):
    print(response.text)
else:
    print("Error : " + response.text)

# 서버로 전달 & 받기
url1 = "https://9615-2001-2d8-e36e-bc62-f4d7-bd0b-1ffc-ff44.jp.ngrok.io/api/weather?str=" + response.text
# url1 = "https://5fb2-223-38-22-85.jp.ngrok.io/api/weather?str=" + "오늘 날씨 알려줘"

response = requests.get(url1)
rescode = response.status_code

if (rescode != 500):
    speak = gtts.gTTS(text=response.text, lang="ko")

    # speak.save("speak.mp3")
    speak.save("speak.mp3")

    # terminal_command = "omxplayer speak.mp3"
    # os.system(terminal_command)
else:
    print("Error : " + response.text)
