import random
from collections import defaultdict


api={}
for i in range(1,101):
    #100 apis - each id for each api
    api[i]="api"+str(i)

users={}
#there are 1000 users, each user has certain apis
for i in range(1,1001):
    users[i]="user"+str(i)

response_time_api=defaultdict(list)
user_api_response=[[[0,0]]*100 for i in range(1001)]

#approx api requests each day - 1M each day
def api_calls():
    for i in range(10**6):
        #getting random api calls using rand function
        current_call=random.randint(1,100)
        #getting random response time for the current api call assuming max of 10ms for each response
        current_response_time=random.randint(1,10)
        #getting random user_id to store the user who uses the current api
        current_user_id=random.randint(1,1000)
        response_time_api[current_call][0]+=current_response_time
        response_time_api[current_call][1]+=1
        #added to get the max avg api for each user
        user_api_response[current_user_id][current_call][0]+=current_response_time
        user_api_response[current_user_id][current_call][1]+=1

#call api calls
api_calls()


#function to get the api with max avg response time
def get_avg_response_time():
    api_id=-1#if not present
    max_avg=0
    #current_avg=0
    for i in response_time_api:
        #getting average time for each api
        avg_api_response=(i[0]/i[i])
        if max_avg<avg_api_response:
            max_avg=avg_api_response
            api_id=api[i]
    return api_id

#function to get the max response time of api for each user
def get_avg_for_each_user():
    user_max_avg=[]*1001
    #traversing the whole list which is available for the users
    for i in range(len(user_api_response)):
        max_avg=0
        for j in range(len(user_api_response[i])):
            avg_api_response=(user_api_response[i][j][0]/user_api_response[i][j][1])
            if max_avg<avg_api_response:
                api_id=api[user_api_response[i]]
                max_avg=avg_api_response
        #storint the api with max avg response api for each user in a vector
        user_max_avg[i]=api_id
    return user_max_avg
