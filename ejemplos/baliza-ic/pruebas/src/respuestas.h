#ifndef PRUEBAS_RESPUESTAS_H
#define PRUEBAS_RESPUESTAS_H

static const char *const RESPUESTA_VACIA = "";

static const char *const RESPUESTA_EXITOSA = R"({
   "@type":"branch",
   "@href":"/repo/6350830/branch/master",
   "@representation":"standard",
   "name":"master",
   "repository":{
      "@type":"repository",
      "@href":"/repo/6350830",
      "@representation":"minimal",
      "id":6350830,
      "name":"dyasc-baliza-ic",
      "slug":"joacomf/dyasc-baliza-ic"
   },
   "default_branch":true,
   "exists_on_github":true,
   "last_build":{
      "@type":"build",
      "@href":"/build/88533221",
      "@representation":"minimal",
      "id":88533221,
      "number":"59",
      "state": "passed",
      "duration":51,
      "event_type":"push",
      "previous_state":"passed",
      "pull_request_title":null,
      "pull_request_number":null,
      "started_at":"2018-10-19T12:00:09Z",
      "finished_at":"2018-10-19T12:01:00Z",
      "private":false,
      "priority":false
   }
})";

static const char *const RESPUESTA_FALLIDA = R"({
        "@type":"branch",
        "@href":"/repo/6350830/branch/master",
        "@representation":"standard",
        "name":"master",
        "repository":{
            "@type":"repository",
                    "@href":"/repo/6350830",
                    "@representation":"minimal",
                    "id":6350830,
                    "name":"dyasc-baliza-ic",
                    "slug":"joacomf/dyasc-baliza-ic"
        },
        "default_branch":true,
        "exists_on_github":true,
        "last_build":{
            "@type":"build",
            "@href":"/build/88533221",
            "@representation":"minimal",
            "id":88533221,
            "number":"59",
            "state": "failed",
            "duration":51,
            "event_type":"push",
            "previous_state":"passed",
            "pull_request_title":null,
            "pull_request_number":null,
            "started_at":"2018-10-19T12:00:09Z",
            "finished_at":"2018-10-19T12:01:00Z",
            "private":false,
            "priority":false
        }
})";

#endif //PRUEBAS_RESPUESTAS_H
