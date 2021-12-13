from flask import Flask

from src.controllers.linerar_controller import linear_api

app = Flask(__name__)

app.register_blueprint(linear_api)


if __name__ == "__main__":
    app.run(host="0.0.0.0", port=8080)
