const Subject = require("../observer/subject");

class NotificationTopic extends Subject {
  constructor(topicName) {
    super();
    this.topicName = topicName;
    this.observers = [];
    this.latestMessage = null;
  }

  registerObserver(observer) {
    this.observers.push(observer);
  }

  removeObserver(observer) {
    this.observers = this.observers.filter(
      (obs) => obs !== observer
    );
  }

  publish(message) {
    this.latestMessage = message;
    this.notifyObservers();
  }

  notifyObservers() {
    this.observers.forEach((observer) =>
      observer.update(this.topicName, this.latestMessage)
    );
  }
}

module.exports = NotificationTopic;
