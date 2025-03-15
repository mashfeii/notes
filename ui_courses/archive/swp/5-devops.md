# DevOps

**Development** is about writing, testing and maintaining the code for software applications. The
focus is on features and bugs.
**Operations** are about managing and maintaining the infrastructure and environments where software
applications run. The focus is on stability, performance, and security.
Historically these were separate teams: lack of collaboration, delay in deployment and feedback, manual
processes and scalability issues.
Around 2008-2009, the idea of **DevOps** emerged, calling for better integration between
development and operations.

## What is DevOps?

A set of practices and philosophies that promote **collaboration** and **communication** between
software development and IT operations teams.

### Areas of DevOps

**Automating Building and Testing:**

- Continuous Integration (CI)
- Automated Testing and Static Analysis
- Separate ephemeral environments (testing environment, product, etc.)
- Communication between author and reviewers (code review)

**Deployment Automation:**

- Deploy a feature to a subset of users
- Deploy without downtime
- Roll back to the prior versions

**Application Performance Management:**

- Metrics and Logging
- Monitoring the system
- Alerting the developer

## Software Testing

**Hierarchy:**

Unit testing → Integration Testing → System Testing → Acceptance Testing

### Unit Testing

Unit testing is a type of software testing where individual components of a software are tested.
A **unit** is the smallest testable part of any software. It usually has one or a few inputs and
usually a single output.

### Test-driven Development (TDD)

TDD is a software development approach where tests are written **before** the actual code:

1. Write ea test
2. Write the code to make the test pass
3. Then refactor the code for improvement

**Fail First:** the first run of the test is expected to fail since it's written before the code
**Incremental Development:** coding is done in small steps. After a test passes, new tests are added
**Refactoring:** when all the tests pass, the code is refactored. The tests are run again
