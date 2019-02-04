#!/usr/bin/env python
# coding: utf-8

# _Building something using data?_
# 
# The Socrata Open Data API allows you to programmatically access a wealth of open data resources from governments, non-profits, and NGOs around the world.
# 
# https://dev.socrata.com/
# 
# 
# The *CDC* data is avalable over Socrata API:
# ![image.png](attachment:image.png)
# 
# 
# 

# Python bindings for the Socrata Open Data API
# * Install sodapy into current notebook environment

# In[1]:


import sys
#get_ipython().system('{sys.executable} -m pip install sodapy')
import pandas
import numpy
import os
from sodapy import Socrata


# Define list of datasets to work with by providing Socrata dataset IDs.
# The quiry used to find these:
# https://healthdata.gov/search/type/dataset?query=2017%20%22Table%20II%22&sort_by=changed&sort_order=DESC&q=search/type/dataset&page=1
# 

# In[2]:


datasets = ["rxmp-xjpc","ttj2-zsyk", "i42d-szcv", 
            "6rpz-c2y5", "9qys-crt2","acdz-tk8j", 
            "n24i-76tn", "btcp-84tv", "m6gf-vfkz","5egk-p6rd"]


# Connect to the site `"data.cdc.gov"`

# In[3]:


client = Socrata("data.cdc.gov", os.environ['SOCRATA_TOKEN'])


# Define what methadata about columns to print for evaluation

# In[4]:


column_properties_we_want_to_see = [
        'dataTypeName',
        'fieldName',
        'width']


# All files have these three columns `['reporting_area','mmwr_year','mmwr_week' ]`.
# 
# Year is 2018 fo all files. We'll drop the `'mmwr_year'` column.
# 
# Other columns named consistently with most formatted as `decease + measure_name`. The `measure name` usually have a suffix further describing the constract.
#  
# Example:
# 
# * `west_nile_virus_disease_neuroinvasive_previous_52_weeks_max`
# * `hepatitis_viral_acute_type_c_previous_52_weeks_med`
# 
# Some are informative a very paricular
# 
# * `vibriosis_any_species_of_the_family_vibrionaceae_other_than_toxigenic_vibrio_cholerae_o1_or_o139_confirmed_previous_52_weeks_max`
# 

# There are planty of columns having `_flag` postfix

# In[5]:


remove_flags= lambda row: dict(filter(lambda kv: not kv[0].endswith('_flag'), row.items()))


# The json numeric data quoted and DataFrame fiels has Objet type insted on Number.
# ```json
# {'zika_virus_disease_non_congenital_previous_52_weeks_max': '3', 'west_nile_virus_disease_nonneuroinvasive_previous_52_weeks_med': '0'}
# ```
# Supply function that converts field to INT 

# In[6]:


to_numbers= lambda row: dict(map(lambda kv: (kv[0],int(str(kv[1]))) if str(kv[1]).isnumeric() else kv, row.items()))


# We'll aggregate columns from different files by adding on the right where aggregated_by matches.

# In[7]:


index_by = ['reporting_area','mmwr_week' ]


# In[13]:



all_three=[]
union_of_all_files_df= None

for dataset in datasets:
    metadata= client.get_metadata(dataset)
    print(metadata['name'])
    all_metadata_about_columns = metadata['columns']
    for a_meta in all_metadata_about_columns:
        out=""
        for meta_key, meta_value in a_meta.items():
            if meta_key in column_properties_we_want_to_see:
                #out+=meta_key
                #out+=" => "
                out+=str(meta_value)
                out+=", "
        if out:
            print(out)
            print('--------------------------')

    il= client.get(dataset, reporting_area='ILLINOIS')
    #print(il)
    mi= client.get(dataset, reporting_area='MICHIGAN')
    oh= client.get(dataset, reporting_area='OHIO')
    ind= client.get(dataset, reporting_area='INDIANA')
    states=il+mi+oh+ind
    # all_three+=
    all_ = list(map(remove_flags, states))
    all__ = list(map(to_numbers, all_))
    print("Four states dataset has: ",len(all__), " records")
    current_df= pandas.io.json.json_normalize(all__)
    current_df.reset_index()
    current_df.drop('mmwr_year', axis=1, inplace=True)
    if 'location_1.human_address' in current_df.columns:
        current_df.drop(['location_1.human_address'
                     ,'location_1.latitude'
                     ,'location_1.longitude'
                     ,'location_1.needs_recoding'], axis=1, inplace=True)
    if 'location_2.human_address' in current_df.columns:
        current_df.drop(['location_2.human_address'
                     ,'location_2.latitude'
                     ,'location_2.longitude'
                     ,'location_2.needs_recoding'], axis=1, inplace=True) 
    if len(all__) > 208:
        print("!!! Potential ERROR!!! dataset has: ",len(all__), " records while 208 (4 states X 52 weeks each) is expected!!!")
        current_df.drop_duplicates(keep= 'first', inplace= True)
        print("Taking a first duplicate! data frame shape is: ",current_df.shape," now")

    print("Tags",client.get_metadata(dataset)['tags'])
    if union_of_all_files_df is not None:
        union_of_all_files_df = union_of_all_files_df.merge(current_df
                                    , on= index_by)
        
    else:
        union_of_all_files_df = current_df
        current_df = None
        print("Init done ")          
        
union_of_all_files_df.set_index(index_by,inplace=True)
print(union_of_all_files_df.shape)


# Print agregated dataset columns:

# In[14]:


print("Columns ",*union_of_all_files_df.columns, sep='\n')


# In[17]:



print("Before dedup shape is: ", union_of_all_files_df.shape)
print(union_of_all_files_df.drop_duplicates(inplace= True))
print("After dedup shape is: ", union_of_all_files_df.shape)
file= open('result.csv','w')
union_of_all_files_df.to_csv(file)
file.close()

#selected_columns_data = 
#for a_column_meta in column_properties_we_want_to_see:
    

#client.get("ttj2-zsyk", limit=2)


# In[18]:


cums = union_of_all_files_df.filter(regex='cum', axis= 'columns')
print(cums.shape)
print(cums.columns)
print(cums.index)


# In[29]:





# In[30]:


mi_cums= cums.loc['MICHIGAN']


print(mi_cums.shape)
print(mi_cums.index)
print(mi_cums.columns)

{}
# In[31]:


print(mi_cums.values)


# In[40]:


#from matplotlib.pyplot import plot
import matplotlib.pyplot as plt
plt.close('all')
mi_cums.plot()
plt.legend(loc='best')
#plt.legend(bbox_to_anchor=(1.03,1), loc="lower left",
#                mode="expand", borderaxespad=0)
plt.show()
#plot('Number of cases', 'Week of the year', data= mi_cums)
