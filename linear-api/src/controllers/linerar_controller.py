from flask import Blueprint, jsonify

linear_api = Blueprint("linear_controller_api", __name__)


@linear_api.route("/api/linear", methods=["GET"])
def solve_linear():
    response = solve_linear()
    return jsonify(response)
