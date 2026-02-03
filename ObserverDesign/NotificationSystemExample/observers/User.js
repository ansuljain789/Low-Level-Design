const Observer = require("../observer/Observer");

class User extends Observer {
  constructor(name) {
    super();
    this.name = name;
  }

  update(topicName, message) {
    console.log(
      `📩 ${this.name} received update from ${topicName}: ${message}`
    );
  }
}

module.exports = User;
