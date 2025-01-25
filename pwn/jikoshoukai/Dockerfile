FROM ubuntu:22.04

RUN apt-get update && apt-get install -y gcc make socat libc6-i386

RUN useradd -m ctf

WORKDIR /home/ctf

COPY jiko.c flag.txt entrypoint.sh jiko ./ 

RUN chown ctf:ctf jiko && chmod 4755 jiko

RUN mv flag.txt /flag.txt && chmod 600 /flag.txt && chown root:ctf /flag.txt

EXPOSE 3030

ENTRYPOINT ["./entrypoint.sh"]