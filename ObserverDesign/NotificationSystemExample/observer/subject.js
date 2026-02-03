class Subject {
  registerObserver(observer) {
    throw new Error("registerObserver() must be implemented");
  }

  removeObserver(observer) {
    throw new Error("removeObserver() must be implemented");
  }

  notifyObservers() {
    throw new Error("notifyObservers() must be implemented");
  }
}

module.exports = Subject;
