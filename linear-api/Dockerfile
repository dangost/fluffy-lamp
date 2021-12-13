FROM python:3.9-slim

WORKDIR /app

COPY src/ /app/src
COPY proj.req /app/

RUN pip install --upgrade pip \
    pip install -r proj.req

CMD ["python", "-m", "src"]
EXPOSE 8080
