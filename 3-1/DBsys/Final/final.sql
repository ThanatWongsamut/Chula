CREATE TYPE MESSAGE_TYPE AS ENUM('MESSAGE', 'IMAGE', 'GEO');
CREATE TYPE TRANSACTION_TYPE AS ENUM('PayEarnest', 'PayRemain', 'Deposit', 'CustomRefund', 'WorkerRefund');

CREATE TABLE MESSAGE (
    "UID" UUID NOT NULL,
    "RecpID" UUID NOT NULL,
    "Type" MESSAGE_TYPE NOT NULL,
    "Data" TEXT NOT NULL,
    "From" UUID NOT NULL,
    "Date" DATETIME NOT NULL,
    PRIMARY KEY ("UID", "RecpID", "Date"),
    FOREIGN KEY ("UID") REFERENCES "USER_DATA"("UID")  
);

CREATE TABLE USER_DATA (
    "UID" UUID NOT NULL,
    "FirstName" VARCHAR(255) NOT NULL,
    "LastName" VARCHAR(255) NOT NULL,
    "PhotoUrl" VARCHAR(255),
    "Gender" CHAR(1) NOT NULL CHECK ("Gender" IN ('M', 'F', 'O')),
    "PhoneNumber" VARCHAR(20) NOT NULL,
    "CitizenID" VARCHAR(13),
    "VerifiedFlag" BOOLEAN NOT NULL,
    "PaymentDetail_Bank" VARCHAR(255),
    "PaymentDetail_Account" VARCHAR(255),
    PRIMARY KEY ("UID")
);

CREATE TABLE CUSTOMER (
    "UID" UUID NOT NULL,
    PRIMARY KEY ("UID"),
    FOREIGN KEY ("UID") REFERENCES "USER_DATA"("UID")
);

CREATE TABLE WORKER (
    "UID" UUID NOT NULL,
    PRIMARY KEY ("UID"),
    FOREIGN KEY ("UID") REFERENCES "USER_DATA"("UID")
);

CREATE TABLE ADMIN (
    "UID" UUID NOT NULL,
    "LOGIN_KEY" BINARY(40) NOT NULL,
    PRIMARY KEY ("UID"),
    FOREIGN KEY ("UID") REFERENCES "USER_DATA"("UID")
);

CREATE TABLE TASK (
    "TaskID" UUID NOT NULL,
    "Title" VARCHAR(255) NOT NULL,
    "Category" VARCHAR(255) NOT NULL,
    "Description" TEXT,
    "Images" TEXT,
    "Location" VARCHAR(255),
    "State" VARCHAR(255) NOT NULL,
    "Wages" DOUBLE PRECISION NOT NULL,
    "StartDateTime" DATETIME NOT NULL,
    "EndDateTime" DATETIME NOT NULL,
    "VerifyFlag" BOOLEAN NOT NULL,
    "CustomerID" UUID NOT NULL,
    PRIMARY KEY ("TaskID"),
    FOREIGN KEY ("CustomerID") REFERENCES "USER_DATA"("UID")
);

CREATE TABLE TRANSACTION_DATA (
    "UID" UUID NOT NULL,
    "TRANS_ID" UUID NOT NULL,
    "Amount" DOUBLE PRECISION NOT NULL,
    "Status" VARCHAR(255) NOT NULL CHECK ("Status" IN ('In Progress', 'Completed')),
    "Datetime" DATETIME NOT NULL,
    "Type" TRANSACTION_TYPE NOT NULL,
    "TaskID" UUID NOT NULL,
    PRIMARY KEY ("TRANS_ID"),
    FOREIGN KEY ("UID") REFERENCES "USER_DATA"("UID"),
    FOREIGN KEY ("TaskID") REFERENCES "TASK"("TaskID")
);

CREATE TABLE WORK_IN (
    "WorkerID" UUID NOT NULL,
    "TaskID" UUID NOT NULL,
    "Status" VARCHAR(255) NOT NULL CHECK ("Status" IN ('In Progress', 'Completed')),
    PRIMARY KEY ("WorkerID", "TaskID"),
    FOREIGN KEY ("WorkerID") REFERENCES "WORKER"("UID"),
    FOREIGN KEY ("TaskID") REFERENCES "TASK"("TaskID")
);

CREATE TABLE ASSIGN_TASK (
    "WorkerID" UUID NOT NULL,
    "TaskID" UUID NOT NULL,
    "CustomerID" UUID NOT NULL,
    "ReviewFromCustomer_Message" TEXT,
    "ReviewFromCustomer_Rating" INT,
    "ReviewFromWorker_Message" TEXT,
    "ReviewFromWorker_Rating" INT,
    PRIMARY KEY ("WorkerID", "TaskID", "CustomerID"),
    FOREIGN KEY ("WorkerID") REFERENCES "WORKER"("UID"),
    FOREIGN KEY ("TaskID") REFERENCES "TASK"("TaskID"),
    FOREIGN KEY ("CustomerID") REFERENCES "CUSTOMER"("UID")
);