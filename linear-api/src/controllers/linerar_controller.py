from flask import Blueprint, jsonify

from src.core.linear_solving import solve_linear

linear_api = Blueprint("linear_controller_api", __name__)


@linear_api.route("/api/linear", methods=["GET"])
def solve_linear_controller():
    response = solve_linear()
    return jsonify(response)
