# SDLC - Waterfall Model

Also, _linear-sequential_ life cycle model: any phase in the development process begins **only** if
the previous phase is complete. It is the **first** widely used approach.

![Waterfall structure](../../attachments/waterfall.jpg)

- **Requirement Gathering and analysis:** all possible requirements of the system to be developed
  are captured in this phase and documented in a requirement specification doc.
- **System Design:** the requirement specifications from first phase are studied in this phase and
  system design is prepared. SD helps in specifying hardware and system requirements and also helps
  in defining overall system architecture.
- **Implementation:** with inputs from SD, the system is first developed in small programs called
  _units_, which are integrated in the next phase. Each _unit_ is developed and tested for its
  functionality which is referred to as **Unit Testing**.
- **Integration and Testing:** all the units developed are integrated into a system after testing of
  each unit. Post integration the entire system is tested for any faults and failures.
- **Deployment of system:** once the functional and non-functional testing is done, the product is
  deployed in the customer environment or released into the market.
- **Maintenance:** there are some issues which come up in the client environment. To fix those
  _patches _ released. Also, to enhance the product some _better version _ released.

## Applications

- Requirements are well documented, clear and fixed.
- Product definition is stable.
- Technology is understood and is not dynamic.
- There are no ambiguous requirements.
- Ample resources with required expertise are available to support the product.
- _The project is short_

### Advantages and disadvantages

| Pros                                                                                                       | Cons                                                             |
| ---------------------------------------------------------------------------------------------------------- | ---------------------------------------------------------------- |
| Simple and easy to understand and use                                                                      | No working software is produced until late during the life cycle |
| Easy to manage due to the rigidity of the model, each phase has specific deliverables and a review process | High amounts of risk and undertainty                             |
| Phases are processed and completed **one at a time**                                                       | Not a good model for complex and object-oriented projects        |
| Works well for smaller projects where requirements are well understood                                     | Poor model for long and ongoing projects                         |
