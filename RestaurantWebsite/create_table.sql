create database restaurantdb;

use restaurantdb;

create table admin(
admin_id int primary key,
admin_password char(15) not null
);

create table menu (
item char(10) primary key,
category char(20) not null,
price float not null,
description char(50)
);

create table registers(
username char(15) primary key,
password char(20) not null
);

create table customer(
user_id int primary key,
username char(15) not null,
address char(20) not null,
zip char(10),
landmark char(20),
cellnumber bigint not null,
email char(20) not null
);

create table orders(
quantity char(15),
deli_addresschar(20),
dates date,
payment_type char(10),
price float,
order_id int primary key,
user_id int not null references customer(user_id),
customername char(15) not null
);

create table credit_card(
card_number bigint,
card_type char(10) not null,
card_name char(15) not null,
card_issuer char(15) not null,
card_expdate char(10),
card_cvv char(10),
order_id int references orders(order_id),
primary key (card_number, order_id)
);

use restaurantdb;

insert into admin value(1, "000000");
insert into admin value(2, "000000");
insert into admin value(3, "000000");
insert into admin value(4, "000000");

insert into registers value("bob","000000");

insert into menu value("鱼香肉丝","肉类",10.00,"用肉和菜做成");

insert into customer value(1, "nick", "Beijing", "100871", "china", "1300000000", "nick@163.com");

insert into orders value(5,"beijing","2016/4/5","card",50.00, 1, 1, "nick");

insert into credit_card value(100010001,"金卡","牡丹卡","工商银行","2020/10/10","",1);