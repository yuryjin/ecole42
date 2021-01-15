FROM ruby
RUN apt-get update -y && apt-get install -y build-essential libpq-dev nodejs sqlite3

MAINTAINER zlucan <zlucan@student.21-school.ru>

ONBUILD COPY app /opt/app
ONBUILD WORKDIR /opt/app

ONBUILD EXPOSE 3000
ONBUILD RUN bundle install
ONBUILD RUN rake db:migrate
ONBUILD RUN rake db:seed

# How to build it?
# docker build -t ft-rails:on-build .
