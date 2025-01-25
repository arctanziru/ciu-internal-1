FROM ubuntu:20.04

RUN apt-get update && apt-get install -y gcc make socat libc6-i386

RUN useradd -m ctf

WORKDIR /home/ctf

COPY challenge.c flag.txt entrypoint.sh challenge ./

RUN chmod 4755 challenge && chown ctf:ctf challenge

EXPOSE 6789

ENTRYPOINT ["./entrypoint.sh"]