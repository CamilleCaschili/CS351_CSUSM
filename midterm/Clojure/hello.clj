(ns hello-world)

(defn concat_name
    [first last]
    (str first " " last)
)

(defn main
    []
    (def firstname "Anakin")
    (def lastname "Skywalker")
    (def age 10)
    (def gpa 3.5)
    (def fullname (concat_name firstname lastname))

    (while (< age 20)
        (do
            (println "You are" age "years old.")
            (def age (+ age 1))
        )
    )

    (doseq [i (range 10)]
        (def age (+ age 1))
    )

    (dotimes [i 10]
        (def age (+ age 1))
    )

    (loop [i 0]
        (if (< i 10)
            (do
                (def age (+ age 1))
                (recur (+ i 1))
            )
        )
    )

    (println "Hello," firstname "!")
    (println "You are" age "years old.")
    (println "Your full name is" fullname)
    (println "Your GPA is" gpa)
)

(main)