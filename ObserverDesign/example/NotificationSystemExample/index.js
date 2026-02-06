const NotificationTopic = require("./subjects/NotificationTopic");
const User = require("./observers/User");

// Create topic
const jobAlerts = new NotificationTopic("Job Alerts");

// Create users
const alice = new User("Alice");
const bob = new User("Bob");

// Users subscribe
jobAlerts.registerObserver(alice);
jobAlerts.registerObserver(bob);

// Publish event
jobAlerts.publish("New MERN Developer job posted");

// Bob unsubscribes
jobAlerts.removeObserver(bob);

// Publish another event
jobAlerts.publish("New Backend Engineer job posted");
