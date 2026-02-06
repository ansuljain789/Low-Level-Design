class Observer {
  update(message) {
    throw new Error("update() method must be implemented");
  }
}

module.exports = Observer;
