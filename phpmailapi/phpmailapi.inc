<?php
/***************************************************************************
 * phpmailapi.inc   Version 0.01
 *               Main file for phpmailapi class
 *
 * authors:      Alexander Meindl <am@meindlsoft.com>
 *               Sven Reul <heffer@quaddamage.de>
 *			     Markus Gsottberger <scotti@scotti.tk>
 *
 *               Released under v2 of the GNU LGPL
 *
 * $Id: phpmailapi.inc,v 1.1 2004/06/22 19:07:19 mr3dblond Exp $
 **************************************************************************/

class phpmailapi
{
   	/**
   	* Unused
   	* Stores the options in the driver classes.
   	*
   	* @var array
   	*/
    	
   	var $options = array();
 
   	/**
   	* Factory
   	* This is the method to initialize an image tool. This method is called statically, 
   	* using the name of the tool and an array of options.
   	*
   	* @access public
   	* @param string $toolname The name of the tool used
   	* @param array $options An array of tool specific options
   	* @return mixed Image tool object or PEAR::Error on failure
   	*/

	function &factory($options)
	{
		if (!is_array($options))
			die("factory error: missing option array");

		// mta driver
		@require_once 'mta/'.strtolower($toolname).".inc";
		if (!class_exists('phpmailapi_mta'))
			die("Class 'phpmailapi_mta not found");
        $obj =& new "phpmailapi_mta";

		// imap driver
		@require_once 'imap/'.strtolower($toolname).".inc";
		if (!class_exists('phpmailapi_imap'))
			die("Class 'phpmailapi_imap not found'");
        $obj =& new "phpmailapi_imap";

		// storage driver (db or text files)
		@require_once 'storage/'.strtolower($toolname).".inc";
		if (!class_exists('phpmailapi_db'.$toolname))
			die("Class 'phpmailapi_db' not found");
        $obj =& new "phpmailapi_db";

        return $obj;
	}

	
	/**
	* Constructor unsed
	* The constructure is only used by inheriting classes to
	* represent the packages driver structure.
	*/

	function phpmailapi( $options = array() )
	{

	}
	
	
	// usable methods:

	############################################################################
	// information

	// Syntax		: array getAllEmailAddresses(string domain [ bool mode])
	// Options		: domain = 
	//				  mode	 = true: information array
	//						   false: only emails {default}
	// Return		: array with email addresses
	// Description	: get all email addresses
	function getAllEmailAddresses($domain, $mode=false)
	{
	}

	function getEmailAddress($domain, $email, $mode=false)
	{
	}

	function getQuota($domain, $email="")
	{
	}

	// Syntax		: array getServerInfo([int mode])
	// Options		: mode = 0: all information
	//					 	 1: mta information
	//					 	 2: imap information
	//					 	 3: storage information
	// Return		: information array
	// Description	: get server information
	function getServerInfo($mode)
	{
	}

	############################################################################
	// email functions

	function addEmailAddress($domain, $email)
	{
	}

	function updateEmailAddress($domain, $email)
	{
	}

	function removeEmailAddress($domain, $email)
	{
	}

	############################################################################
	// email functions

	function addEmailAlias($domain, $email, $alias)
	{
	}

	function updateEmailAlias($domain, $email, $alias)
	{
	}

	function removeEmailAlias($domain, $email, $alias)
	{
	}

	############################################################################
	// vdomain functions

	function addvdomain($domain)
	{
	}

	function updatevdomain($domain)
	{
	}

	function removevdomain($domain)
	{
	}
}
?>
