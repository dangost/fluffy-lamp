FROM python:3.9-slim

WORKDIR /app

COPY src/ /app/src
COPY req.txt /app/

RUN pip install -r req.txt

CMD ["python", "-m", "src"]
EXPOSE 8080
