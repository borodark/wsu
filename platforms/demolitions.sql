create table demolitions(
Address varchar(255),
Parcel_ID varchar(255),
Contractor_Name varchar(255),
Price varchar(255),
Primary_Funding_Source varchar(255),
Demolition_Date date,
Commercial_Building varchar(255),
Council_District varchar(255),
Neighborhood varchar(255),
Latitude varchar(255),
Longitude varchar(255),
Location varchar(255)
);

LOAD DATA local INFILE 'datasets_Detroit_Demolitions.csv' INTO TABLE demolitions FIELDS TERMINATED BY ',' LINES TERMINATED BY '\r';
