## API Guide
first api made using rust

API of a task manager , thats only create tasks (not users)
The main url is `http://127.0.0.1/`

*Tasks states possible*

```rust
pub enum TaskState {
    NotStarted,
    InProgress,
    Completed,
    Paused,
    Failed
}
```
the default state is `NotStarted`

#### Routes
* Create task with POST request at `/task/`

> expected Json
```json
{
  "user_id": "<uuid of user>",
  "task_type": "",
  "souce_file": ""
}
```
> returned Json 
```json
{
 "task_id": "<uuid of the new task"
}
```

* Get task with GET request at `/task/<uuid of task>`

> returned Json

```json
{
  "user_uuid" : "<user id>",
  "task_uuid" : "<task id>",
  "task_type" : "<type of task>",
  "state": "<Current state of task>",
  "source_file": "<file source>",
  "result_file": "<null if not completed task>"
}
```

* Modify state of task with PUT request at`/task/<uuid of task>/<task new state>` task new state can be `["start","pause","fail"]` *no body required*

> returned Json 
```json
{
 "task_id": "<uuid of the task"
}
```

* Modify state of task for *completed* with PUT request at`/task/<uuid of task>/complete`

> espected Json
```json
{
  "result_file": "<path of result>"
}
```

> returned Json 
```json
{
 "task_id": "<uuid of the task"
}
```


